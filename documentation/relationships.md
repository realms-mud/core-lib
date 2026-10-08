# Relationships

Relationships represent current directional interpersonal state. Experiences
record the events explaining that state. Opinions, faction reputation, quest
state, and combat statistics remain independent.

## Refined implementation plan

The existing scaffold is extended rather than replaced with a parallel domain:

1. Make the realization module authoritative; remove singleton relationship
   state and history accumulation.
2. Centralize identity, dimension validation, bounds, and derived queries in
   the stateless service. Keep the existing singular service name; the plural
   name resolves to the same service.
3. Wire the existing secure player save/restore domain. Persist a player's
   outgoing relationships and named NPC attitudes toward that player.
4. Add explicit authored conversation, quest, and structured interaction
   effects; retain existing opinion behavior.
5. Add directional prerequisite and limitor conditions, including numeric
   thresholds and derived classifications.
6. Prove direction, isolation, bounds, semantic event recording, quest-to-
   prerequisite progression, and persistence with remote LPC tests.
7. Persist named NPC-to-NPC relationships with atomic bounded updates, and
   cache derived summaries without making the cache authoritative.
8. Complete persistent timed NPC mentorship through the research lifecycle.
9. Wire combat intervention, betrayal, consensual barter, and default NPC AI
   to actual successful gameplay actions.

No arbitrary emote parsing, automatic faction-to-interpersonal conversion,
or new relationship-history database is introduced. NPC AI uses the existing
living heartbeat; relationship state itself has no heartbeat subscription.

## Identity and ownership

Living realizations already inherit `/lib/modules/relationships.c`.
`getModule("relationships")` resolves to the owning realization.
`getService("relationship")` and `getService("relationships")` resolve to the
same stateless service.

Use `getService("relationship")->identity(actor)` for authored identity strings.
NPC identity is program path plus the name at first relationship use, shared
across respawns and room instances. Do not use a display description, alias,
or clone object name as a persistent target. Player identities use the player
program path and character name, including in player-derived test objects.
Changing a player's character name requires a data migration.

A player owns their outgoing relationships. A named NPC's attitude toward a
player lives in that player's incoming relationships, so NPC destruction or a
reboot cannot erase it or leak it into another player's state. NPC-to-NPC
relationships are database-authoritative and persist immediately, independently
of player saves. Clones sharing a named identity see the same outgoing state.
Player-to-player relationships are owned by the
source player; queries against an offline player's attitudes require loading
that player's state rather than consulting a singleton.

NPC methods require a live player object for player endpoints. Passing an
offline player identity to NPC world-storage queries or mutations raises an
error rather than creating a duplicate world record. A live player's incoming
API accepts named NPC identities, including destroyed teachers.

## Dimensions

| Dimension | Minimum | Maximum |
|---|---:|---:|
| trust, respect, affection | -100 | 100 |
| gratitude, fear, suspicion, rivalry, admiration, obligation | 0 | 100 |

An absent relationship or dimension has numeric value zero. Invalid identities,
self relationships, invalid dimensions, and non-integer changes raise errors.
The complete change mapping is validated before any dimension is modified.
Values are clamped to the dimension's bounds.

Definitions are centralized in the service; adding a dimension requires no
storage schema change. Derived dispositions are `stranger` (no record),
`acquaintance`, `ally`, `trusted ally`, `friend`, `rival`, and `enemy`.
Enemy and rival checks precede positive classifications. Friendship requires
trust >= 60, respect >= 50, and affection >= 40; trusted allies require
trust >= 75 and respect >= 60; allies require trust >= 40 and respect >= 30.

Mentor/student, romantic consent, employment, and debt agreements cannot be
inferred reliably from numeric dimensions alone and are not classifications.
Strength is the mean absolute value of the defined dimensions (0 through 100),
not a substitute for the individual dimensions. Derived classification,
strength, and dominant dimension are cached by endpoint identity, revision,
and dimension snapshot. Restore clears the player's cache; snapshot comparison
also invalidates caches held by surviving NPCs when restored revisions repeat.
World reads remain database-authoritative; caching avoids recalculation, not
the read needed to detect another clone's changes.

## API

```c
actor->relationshipToward(target);
actor->relationshipFrom(source);
actor->relationshipValue(target, "trust");
actor->modifyRelationship(target, "trust", 5);
actor->setRelationshipValue(target, "trust", 25);
actor->updateRelationshipToward(target, ([ "trust":5, "respect":2 ]));
actor->updateRelationshipFrom(npcIdentity, ([ "trust":10 ]));
actor->relationshipType(target);
actor->relationshipSummary(target);
actor->relationshipSummary(source, "from");
actor->queryRelationships(([ "trust":50 ]));
```

Snapshots cannot mutate stored dimensions. `relationshipWith`,
`relationshipData`, and `hasRelationship` are convenience names for the
existing directional APIs. Source-local queries enumerate outgoing records;
NPC attitudes held by players are queried directly with a target player,
not discovered globally.

Low-level mutations change truth only. Producers record their gameplay event
separately, or use the explicit combined API:

```c
player->recordRelationshipInteraction(npc, "combat.rescue",
    ([ "trust":10, "gratitude":20 ]),
    ([ "reason":"rescued from an orc" ]), "from");
```

`from` means NPC -> player; `toward` means player -> NPC. This corrects the
original plan's rescue example, which accidentally labeled Bob's gratitude
as Alice -> Bob. The observation belongs to the initiating player and records
both relationship endpoints in metadata.

## Authored producers

NPCs may opt into specific successful interactions in `Setup()`:

```c
addRelationshipInteraction("social.bow", ([ "respect":1 ]));
addRelationshipInteraction("gift.received", ([ "gratitude":5 ]));
addRelationshipInteraction("training.completed", ([ "respect":2 ]));
addRelationshipInteraction("faction.helped:monks", ([ "trust":3 ]));
```

Successful targeted soul commands call `social.<action>`; freeform emotes do
not. Existing blocking and opinion behavior remains in place. Giving an item
calls `gift.received` after transfer and records `gift.given`. No effect occurs
without an authored rule. These small reusable social rules are intentionally
repeatable; quest-specific or high-value gifts should use explicit authored
quest effects rather than these repeatable rules.

Conversation responses support an additional effect:

```c
addResponseEffect("topic", "selection", ([
    "relationship":([ "trust":5, "respect":2 ])
]));
```

The effect changes the conversation owner's attitude toward the player and
records `conversation.relationship` alongside `conversation.response`.
Use relationship prerequisites on topics or responses to consume that state.

Individual responses can explicitly alter either or both matrix directions:

```c
addResponseEffect("promise", "keep my word", ([
    "relationship":([
        "from":([ "trust":10, "suspicion":-5 ]),
        "toward":([ "respect":3, "obligation":2 ])
    ])
]));
```

`from` changes owner -> player; `toward` changes player -> owner. Values are
bounded deltas, not absolute assignments. Either direction may be omitted.
Only the selected response applies; response prerequisites are checked again
before effects execute. Invalid dimensions, directions, or non-integer deltas
are rejected at authoring. Observations identify the topic and selected response.
The original flat mapping remains compatible and means owner -> player.

Quest definitions may attach directional effects to a state:

```c
addRelationshipEffect("task complete", npcIdentity,
    ([ "trust":10, "respect":5, "gratitude":10 ]), "from");
```

Effects apply on the first entry into that state during a quest run, not on
repeated completion calls. Resetting the quest begins a new run. Experiences
retain `quest.advanced`, outcome observations, and `quest.relationship`.
The Test of Obedience and Uhrdalen conversation provide concrete authored
content integrations.

`learnResearchFrom(teacher, researchItem)` accepts NPC teachers, uses normal
research costs and prerequisites, and requires the teacher to know the research.
It captures the teacher identity and authored completion changes at lesson
start. Immediate research records `training.completed` immediately; timed
research records it only when the normal heartbeat completes learning.
Pending lesson metadata survives player save/restore and teacher destruction.
Starting or continuing a lesson does not apply completion effects; completed
lessons remove their metadata and do not apply again on later heartbeats.

`updateFactionDisposition(faction, amount, killedMember, witness)` optionally
notifies an explicitly supplied NPC of `faction.helped:<faction>` or
`faction.harmed:<faction>` after an actual reputation change. It does not
discover witnesses or affect unrelated faction members.

## Gameplay workflows and default NPC AI

All NPCs inherit relationship-driven AI by default. Neutral relationships do
not prevent existing attacks or trigger assistance. NPCs refuse initiating
attacks against allies, trusted allies, and friends, but may retaliate against
an opponent already fighting them. Idle NPCs in non-peaceful rooms intervene
for known allies. Fear >= 75 triggers an escape attempt during combat; a failed
attempt is not reported as a successful action.

`protect <target>` intervenes against one of the target's current opponents.
Successful intervention engages the protector and removes that opponent from
the protected character's fight. A character at <= 25% maximum hit points with
no opponents remaining produces `combat.rescue`; other interventions produce
`combat.protected`. Failed intervention produces no relationship effect.
Initiating an attack against someone who trusts the attacker produces
`combat.betrayal` once when that fight begins, not on every combat round.

Barter commands:

```text
trade <item> with <target> for <item>
accept trade from <target>
decline trade from <target>
```

Players must explicitly accept. NPCs automatically accept only nonnegative
fair-value offers (offered value >= requested value) from non-enemies/non-rivals.
Participants must be alive, co-located, and not fighting each other. Items must
be directly owned, unequipped, and transferable. Acceptance rechecks ownership,
equipment, flags, NPC willingness, and carrying capacity. Failed transfer restores
surviving items to their owners; decline or failure produces no relationship
effect. Offers expire after 120 seconds and are intentionally not persisted.

Completed barter records one `trade.completed` observation per participant and
changes both directed relationships. Port cargo trading and anonymous shops
remain unrelated to interpersonal transactions.

Central defaults are overridden by an actor's authored interaction rule:

| Event | Changes in the affected actor's attitude |
|---|---|
| combat.protected | trust +5, respect +3, gratitude +10 |
| combat.rescue | trust +10, respect +5, gratitude +20 |
| combat.betrayal | trust -30, respect -15, suspicion +20 |
| trade.completed | trust +2, respect +1 |
| training.completed | respect +2, admiration +1 |

Protection/rescue change the protected character's attitude toward the
protector; betrayal changes the victim's attitude toward the attacker.
The initiator owns the observation, so attacking a trusted NPC preserves
the betrayal evidence in the player's save even after that NPC is destroyed.
Mentorship changes the teacher's attitude toward the learner.
Low-level relationship mutations still do not invent observations.

## Prerequisites and limitors

```c
addPrerequisite("trusted by my teacher", ([
    "type":"relationship",
    "target":npcIdentity,
    "direction":"from",
    "dimension":"trust",
    "minimum":10,
    "maximum":100
]));
```

Minimum and maximum are inclusive; either may be omitted, but not both.
A classification condition uses `"classification":"ally"` instead of a
dimension and numeric bounds. Classification equality is exact, not a social
rank ordering.

Targets are canonical identity strings, `"owner"` (conversation/prerequisite
owner), or `"target"` (runtime ability target). A missing runtime endpoint or
unsupported realization fails closed. Numeric conditions use the zero baseline
even if no record exists.

```c
addSpecification("limited by", ([
    "relationship":([
        "target":"target",
        "direction":"from",
        "dimension":"trust",
        "minimum":50
    ])
]));
```

## Persistence and deployment

Apply migrations `0014_incoming_relationships.sql` and
`0015_relationship_interactions.sql` after the existing migrations.
The mudlib database version is 15; fresh test-database teardown includes the
new tables and stored procedures so rebuilds cannot leave dangling foreign keys.
Incoming dimensions use stored-procedure upserts and a cascading player foreign
key. Outgoing dimensions retain the existing tables and procedures. Saves no
longer prune all relationships, avoiding loss of unrelated persisted targets.
The existing player persistence pipeline now includes the relationship domain.
Do not concurrently edit the same character through multiple live objects;
dimension writes follow the existing player's single-writer save lifecycle.
Research progress, pending mentorships, observations, and relationships share
a save transaction so completion truth and its historical evidence commit
together. World NPC updates use a separate atomic transaction with bounded
stored-procedure deltas and per-dimension revisions.

Legacy relationship history remains readable and importable, with duplicate
imports suppressed. No new gameplay mutation adds entries to that table.
All new historical explanation belongs to Experiences. Old history is not
deleted or fabricated into observations.

Run targeted validation through `build.sh` with the relationship service,
module, persistence, conversation, quest, soul, give, and prerequisite tests.
The trade command and relationship-combat fixtures exercise actual workflows,
including consent, rejected transfer rollback, rescue, betrayal, and default AI.
Local editor diagnostics do not validate LPC.
