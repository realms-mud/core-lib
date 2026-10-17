# Experiences and Observations

Experiences record historical facts. Producers supply domain meaning;
prerequisites and limitors interpret the resulting history. Combat statistics
remain independent and unchanged.

## Module and Service

Living realizations inherit `/lib/modules/experiences.c`. History belongs to
a persisted player, identified by the numeric player ID loaded on restore.
The module retains no observations, pending queue, history cache, or type
index. NPCs and guests do not maintain independent observation histories.
NPCs involved in an interaction are recorded as actors, subjects, or
participants in the triggering player's database history.

The public module API is:

```c
recordObservation(mapping observation)
queryObservations(mapping criteria, int limit = 50, int offset = 0)
countObservations(mapping criteria)
hasObservation(mapping criteria, int minimum = 1)
recordsObservations()
```

Recording writes immediately through the database stored procedure and
returns a normalized mapping. Invalid input or an inactive owner returns zero;
database failures raise an error. There is no delayed save or implicit retry.
Actor defaults to the owner. An NPC can submit an event to the affected player
with itself as actor; a caller cannot impersonate an unrelated actor.
Queries return independent snapshots with a default page of 50 and a hard
maximum of 100 records. Counts and threshold decisions return scalars, not
observation mappings. Normalization alone does not access the database.

`getService("experiences")` supplies normalization, matching, and context
capture. Explicit delegation is supported:

```c
getService("experiences")->recordObservation(
    getModule("experiences"), observation);
```

Only the plural module and service names are supported. Whole-history log and
summary APIs, including `experiencesLog()`, `experiencesSummary()`, and service
array-query APIs, have been removed. The singleton service holds one data
service object but no player histories or per-player mapping cache.

## Records and Queries

Canonical fields are `ID`, `type`, `actor`, `subject`, `participants`, `timestamp`,
`location`, `context`, and `metadata`. Missing optional fields receive empty
defaults; timestamp and location default to the recording time and place.
Objects become identity strings before persistence, including nested values.
Location objects become their program paths. Identities use program path and
name, not a live object reference or a guaranteed unique NPC identifier.

Criteria match canonical fields, or context and metadata keys directly.
Mapping criteria perform recursive subset matching. Arrays match membership;
strings compare case-insensitively. A type such as `combat` matches itself and
descendants such as `combat.kata`, but not `combatant`.

```c
player->countObservations(([
    "type": "combat.kata",
    "target race": "orc",
    "weapon": "katana",
    "kata": "falling-leaf"
]));
```

Two timestamp boundaries, `since` and `until`, are inclusive. The historical
calendar predicate below matches within 60 minutes of midnight, including
the preceding day's final hour:

```c
player->countObservations(([
    "type": "combat",
    "time window": ([ "center": 0, "minutes": 60 ])
]));
```

The center is minutes after midnight (0 through 1439); the radius is 0 through
720 minutes. Missing historical time and malformed predicates do not match.
There are no arbitrary expressions or general-purpose query operators.

## Producers

Every successful active research use records `research.use` by default,
including composite and constructed abilities. An explicit observation type
replaces that default with a specialized event such as `combat.kata`:

```c
addSpecification("observation type", "combat.kata");
```

Active ability context is captured before effects run, then committed only on
successful execution. Rituals record successful completion, not failed or
unfinished attempts. Sustained activation records `research.use` with
`activation: sustained`; successful deactivation records
`research.deactivated`. Automatic repeated composite ticks and sustained
maintenance do not produce additional use records. Combat context includes target
identity, name, race and level, primary weapon blueprint and identity, state,
active sustained research when available, season, moon phase, and time of day.
Explicit producer context takes precedence over captured facts.

Combat records `combat.started` when an opponent is newly registered and
`combat.ended` when that opponent is removed. Repeated registration or removal
does not duplicate these events. Kills retain `combat.kill` alongside existing
combat statistics, while the dying actor records `combat.death`. Successful
escape records `combat.fled` and ends the former opponents' combat
relationships; a blocked escape records neither fleeing nor combat end.

Successful consumption records `consumption.food`, `consumption.drink`,
`consumption.drug`, or `consumption.alcohol` only when biological state actually
changes. The consumed item is the subject. Context contains `item` (program
path), `item name`, `blueprint`, `biological effect`, `biological strength`, and
`before` and `after` state mappings. Those mappings contain `intoxicated`,
`drugged`, `stuffed`, `soaked`, and `headache`, plus `hit points`, `spell points`,
and `stamina points` when combat resources are available. Failed consumption,
successful no-ops, and later biological heartbeat changes do not record events.

The owning module captures shared context at recording time. Available actor
race, guilds, factions, region identity/name, environment/quest state, calendar
minutes after midnight, day, and year accompany events. Combat, research, and
craft events additionally capture equipped item blueprints, materials,
craftsmanship, equipment locations, active sustained research, and effect
traits. An ability's pre-effect snapshot overrides subsequent capture.

Other hooks record movement entry, research milestones and selections,
quest transitions and outcomes, explicit conversation starts and responses,
craft lifecycle events, faction membership and disposition transitions, and
changed persisted character state. Movement retains the existing leave record
for compatibility and captures `from`, realized `to`, direction, and source
and destination regions after entry. Research includes available tree
membership and source, plus guild when the source is an actor guild. Craft
events use the `craft.*` prefix and capture blueprint-backed recipe, materials,
and craftsmanship before destruction; failed attempts include required
material quantities. `faction.reputationChanged` captures previous and final
stored reputation only when it actually changes.

Successful structured soul commands record `social.emote` with canonical
`action`, lowercase `adverb`, `emote type: soul`, `explicit: 1`, target identity,
participants, and location. Invalid or blocked commands do not record.
Explicit valid conversation topic renders record `conversation.topic`;
consecutive repeats of the same topic for the same actor/NPC are suppressed.
Automatic topic chains are not explicit topic observations. Response menus
are isolated per actor; selection rechecks topic and response prerequisites.

No attacks, hits, resource changes, generic heartbeat events, or arbitrary
emote text are automatically logged. Conversation records contain explicit
topic and response identifiers, not inferred promises or insults.

## Rules

An observation prerequisite requires a positive count and criteria:

```c
addPrerequisite("kata practice", ([
    "type": "observation",
    "criteria": ([ "type": "combat.kata", "target race": "orc" ]),
    "value": 100
]));
```

A limitor uses a flat filter with a positive `minimum`:

```c
addSpecification("limited by", ([
    "observation": ([
        "type": "combat.kata",
        "target race": "orc",
        "minimum": 100
    ])
]));
```

Unsupported realizations fail these checks. Neither rule changes history,
combat statistics, or faction state.

## Persistence and Validation

Players write observations immediately through
`/lib/modules/secure/dataServices/experiencesDataService.c` and the
`saveExperienceObservation` stored procedure. Apply database migrations through
`0017_database_experience_queries.sql` before deploying the LPC changes.
The database assigns its existing `AUTO_INCREMENT` primary key on insertion.
Normal recording does not fetch that ID back into the driver; explicit bounded
queries return it as a string-valued `ID` for compatibility with older IDs.
`generateGuid()` and its cache have been removed. Legacy stored IDs remain
readable and repeated explicit writes with an existing ID remain idempotent.

Explicit recording returns the assigned ID without modifying the input
observation. Legacy snapshot imports also leave input observations unchanged,
so reusing an unidentified observation template for another player creates
new database-owned IDs rather than copying an assigned ID between players.
The v2 serializer uses descriptive `string`, `mapping`, `array`, `integer`,
and `float` tags. Nested context and metadata retain scalar types, and the
reader still accepts the previous v1 marker with descriptive tags and plain
delimiter formats. One-letter serialization tags are not supported.
NPCs and guests retain no experience data. NPC assistance and retreat events
are attached to the affected player's history with the NPC as actor.

Migration 13 includes the typed search document, SQL predicate functions,
backfill, triggers, and composite `(playerId, searchType, observationTime)`
and `(playerId, observationTime)` indexes.
Migration 17 adds `prepareExperienceQuery`, which decodes the criteria once,
extracts indexed type/time predicates, and prepares the remaining typed query.
Simple type/time queries avoid the recursive JSON matcher entirely. Compound
filters keep the existing typed recursive matching semantics. Aggregate queries
execute in the procedure without returning record result sets; this avoids the
LDMud MySQL driver's multiple-result-set limitation. Explicit bounded record
queries execute the prepared statement outside the procedure.

Restore fetches no observation rows. Normal player saves neither send nor
rewrite history. Counts cover the complete database history. Existence and
minimum-count queries stop after the required number of matches, including
research prerequisites and limitors. Pagination applies after filtering, in
database insertion order. Other player instances see a recorded event
immediately, without waiting for a character save. Failed inserts are reported
and are not retained in memory for a later save.

The Falling Leaf research item is a test fixture, not a production monk guild
addition. `combatObservationTest.c` executes it 100 times against an orc named
Bob while wielding a katana, queries calendar and technique context, and
checks prerequisite and limitor thresholds at 99, 100, and 101, including the
eligibility of a follow-on Falling Leaf Mastery research fixture. Failed uses
are excluded. Persistence tests cover reloads and append-only stale saves.

The generic Observant Diplomat fixture exercises the real player workflow:
research unavailable, successful `smile`, save/restore of history, research
available, learning through `initiateResearch`, and persistence of the learned
item through another reload. It adds no production monk content.

QA tests cover nested and legacy descriptive formats, malformed criteria,
SQL injection, immediate visibility, player isolation, bounded pages,
auto-increment IDs, NPC-to-player attribution, and explicit write failures.
General unit tests use actor-local observation call captures and the pure
matching helpers; their observation writes never access the database.
These captures are test-only and disappear with the actor. No persistence
enable/disable switches or database-name checks are required. Dedicated
database, persistence, and performance tests use real persisted players and
stored procedures.
EXPLAIN on 1,000 representative noise rows verifies the composite indexes.
The performance fixture checks unchanged `OI_DATA_SIZE_TOTAL` after recording
100 events and after querying a 1,001-row history. It requires fewer than
400,000 evaluation units to record those 100 events, fewer than 10,000 for
the indexed count, and less than 1,000 units of query-cost growth between
1 and 1,001 stored rows. A separate 1,000-event NPC test verifies no retained
history and fewer than 100,000 evaluation units. These are scoped regression
thresholds, not production database-latency guarantees.

No separate area, weather, stance, general active-research, recipe, or quality
getter exists in the inspected APIs. Unsupported facts are omitted rather
than invented: regions identify location, active sustained research identifies
maintained abilities, blueprints identify recipes, and craftsmanship describes
item quality. The current environment weather adjustment is a stub. Retention
policy and production monk progression are intentionally not implemented.