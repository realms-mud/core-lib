# Experiences and Observations

Experiences record historical facts. Producers supply domain meaning;
prerequisites and limitors interpret the resulting history. Combat statistics
remain independent and unchanged.

## Module and Service

Living realizations inherit `/lib/modules/experiences.c`. Other realizations
can opt in by inheriting that module. The module owns its observation log;
queries never retrieve another realization's log from a singleton cache.

The public module API is:

```c
recordObservation(mapping observation)
queryObservations(mapping criteria, int limit = 0, int offset = 0)
countObservations(mapping criteria)
hasObservation(mapping criteria)
```

Recording returns a normalized mapping, or zero for invalid input. Querying
returns independent snapshots. Actor defaults to the owning realization;
recording on behalf of another actor is rejected.

`getService("experiences")` supplies normalization, matching, and context
capture. Explicit delegation is supported:

```c
getService("experiences")->recordObservation(
    getModule("experiences"), observation);
```

Only the plural module and service names are supported. The module also
provides `experiencesLog()` and `experiencesSummary()` snapshots. Service-only
logs do not exist: the service holds no actor history, discovers no owning
module, and only queries or summarizes explicitly supplied observation arrays.

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

Persistent players save observations through the existing secure data service
`/lib/modules/secure/dataServices/experiencesDataService.c`, using the
`experiences` persistence domain and `/lib/modules/secure/experiences.h`,
and `saveExperienceObservation` stored procedure. Apply database migrations,
including `0013_append_only_experience.sql`, before deploying the LPC changes.
The `ID` mapping field is generated by `generateGuid()`, which calls the
database's `UUID()` function. It remains unchanged through normalization,
repeated saves, and reloads, making repeated saves idempotent. Existing stored
IDs are retained; stale saves do not delete newer observations.
The v2 serializer uses descriptive `string`, `mapping`, `array`, `integer`,
and `float` tags. Nested context and metadata retain scalar types, and the
reader still accepts the previous v1 marker with descriptive tags and plain
delimiter formats. One-letter serialization tags are not supported.
Nonpersistent realizations retain only an in-memory log.

Migration 13 includes the typed search document, SQL predicate functions,
backfill, triggers, and composite `(playerId, searchType, observationTime)`
and `(playerId, observationTime)` indexes. No migration 14 is required.
Restore loads only the most recent 100 rows into the local log. Persistent
`queryObservations`, `countObservations`, and `hasObservation` query complete
database history and merge unsaved observations, excluding pending IDs from
database results to prevent double counting. Pagination applies after
filtering, in database insertion order followed by pending insertion order.
The local `experiencesLog` and `experiencesSummary` are cache snapshots, not
lifetime-history exports. Nonpersistent realizations keep their in-memory APIs.

Saves submit only pending observations through the stored procedure. The batch
is committed as a transaction before its IDs are acknowledged; failed batches
roll back and remain pending for retry. Duplicate IDs are immutable no-ops;
other SQL errors are not ignored. Stale players never rewrite restored history.

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

The module maintains derived hierarchical type indexes and rebuilds them on
restore. Counts avoid cloning result arrays, and existence checks stop on the
first match. Database counts and existence use SQL aggregates without loading
observation arrays. SQL filtering preserves the live matcher's typed recursive
semantics, and pagination filters before applying offset and limit.
Real QA tests cover nested and legacy descriptive formats, malformed criteria,
SQL injection, lifetime prerequisites beyond the bounded cache, pending overlap,
delta-only saves, and failed-batch retries. EXPLAIN on 1,000 representative
noise rows verifies that both composite indexes are selected; it is not a
million-row benchmark. A scoped 1,000-record in-memory benchmark with
10 matching entries measured 3,305 evaluation units for indexed counting
versus 215,201 for a full scan; this is not a latency guarantee.

No separate area, weather, stance, general active-research, recipe, or quality
getter exists in the inspected APIs. Unsupported facts are omitted rather
than invented: regions identify location, active sustained research identifies
maintained abilities, blueprints identify recipes, and craftsmanship describes
item quality. The current environment weather adjustment is a stub. Retention
policy and production monk progression are intentionally not implemented.