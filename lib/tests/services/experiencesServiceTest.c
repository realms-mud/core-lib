//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Service;
object Actor;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = clone_object("/lib/services/experiencesService.c");
    Actor = clone_object("/lib/tests/support/services/mockPlayer.c");
    Actor.Name("Observation actor");
    move_object(Actor, "/lib/tests/support/environment/fakeEnvironment.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Actor);
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void NormalizationDoesNotStoreHistory()
{
    mapping result = Service.normalizeObservation(([
        "type": "combat.kata",
        "actor": Actor
    ]));
    ExpectEq("combat.kata", result["type"]);
    ExpectTrue(result["timestamp"] > 0);
    ExpectEq(0, Actor.countObservations(([])));
    ExpectFalse(Service.normalizeObservation(([
        "type": "combat.kata",
        "actor": Actor,
        "metadata": "invalid"
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void NormalizationDoesNotAllocateObservationIds()
{
    mapping first = Service.normalizeObservation(([
        "type": "combat.kata",
        "actor": Actor
    ]));
    mapping second = Service.normalizeObservation(([
        "type": "combat.kata",
        "actor": Actor
    ]));
    ExpectFalse(member(first, "ID"));
    ExpectFalse(member(second, "ID"));
    ExpectFalse(member(Service.normalizeObservation(first), "ID"));
    first["ID"] = "123";
    ExpectEq("123", Service.normalizeObservation(first)["ID"]);
    ExpectFalse(member(first, "_observationId"));
}

/////////////////////////////////////////////////////////////////////////////
void ExplicitModuleRecordingDoesNotCreateServiceHistory()
{
    ExpectTrue(Service.recordObservation(Actor, ([
        "type": "combat.kata"
    ])));
    ExpectEq(1, Actor.countObservations(([])));
    ExpectFalse(function_exists("countObservations", Service));
}

/////////////////////////////////////////////////////////////////////////////
void HistoryAndSummaryApisAreAbsent()
{
    ExpectFalse(function_exists("experiencesLog", Actor));
    ExpectFalse(function_exists("experiencesSummary", Actor));
    ExpectFalse(function_exists("summarizeObservations", Service));
}

/////////////////////////////////////////////////////////////////////////////
void ContextCapturePreservesProducerFacts()
{
    Actor.Race("orc");
    mapping result = Service.buildObservationContext(Actor, ([
        "type": "combat.kata",
        "subject": Actor,
        "context": ([ "target race": "elf", "stance": "tiger" ])
    ]));
    ExpectEq("elf", result["target race"]);
    ExpectEq("tiger", result["stance"]);
    ExpectTrue(member(result, "moon phase"));
}

/////////////////////////////////////////////////////////////////////////////
void DetailedContextIsLimitedToCombatResearchAndCrafting()
{
    Actor.Race("human");
    foreach(string type in ({ "combat.kata", "research.learned",
        "craft.completed", "movement.enter" }))
    {
        int detailed = type != "movement.enter";
        mapping context = Service.buildObservationContext(Actor, ([
            "type":type,
            "subject":Actor
        ]));
        ExpectEq("human", context["race"]);
        ExpectTrue(member(context, "guilds"));
        ExpectTrue(member(context, "factions"));
        ExpectEq(detailed, member(context, "equipment"));
        ExpectEq(detailed, member(context, "active research"));
        ExpectEq(detailed, member(context, "effects"));
        ExpectEq(type == "combat.kata", member(context, "target identity"));
    }
}

/////////////////////////////////////////////////////////////////////////////
void CombatContextCapturesEquippedWeaponAndTarget()
{
    Actor.Race("human");
    Actor.Str(20);
    object weapon = clone_object("/lib/items/weapon.c");
    weapon.set("blueprint", "katana");
    move_object(weapon, Actor);
    ExpectTrue(Actor.equip(weapon));
    mapping context = Service.buildObservationContext(Actor, ([
        "type":"combat.kata",
        "subject":Actor
    ]));
    ExpectEq("katana", context["weapon"]);
    ExpectEq(sprintf("%s#any", program_name(weapon)),
        context["weapon identity"]);
    ExpectEq(({}), context["equipment"]);
    ExpectEq(Actor.Name(), context["target name"]);
    ExpectEq("human", context["target race"]);
    ExpectEq(Actor.effectiveLevel(), context["target level"]);
    destruct(weapon);
}

/////////////////////////////////////////////////////////////////////////////
void ExplicitRoomContextWorksWithoutAnActor()
{
    object room = environment(Actor);
    mapping context = Service.buildObservationContext(0, ([
        "type":"movement.enter",
        "location":room
    ]));
    ExpectTrue(member(context, "environment state"));
    ExpectEq(room.currentState(), context["environment state"]);
    ExpectTrue(member(context, "season"));
    ExpectFalse(member(context, "race"));
    ExpectFalse(member(Service.buildObservationContext(0, ([
        "type":"movement.enter"
    ])), "environment state"));
    ExpectEq(([]), Service.buildObservationContext(0, 0));
}

/////////////////////////////////////////////////////////////////////////////
void MatcherPreservesFieldPrecedence()
{
    mapping observation = ([
        "type":"combat.kata",
        "shared":0,
        "context":([
            "shared":1,
            "context value":"SNOW"
        ]),
        "metadata":([
            "shared":2,
            "context value":"rain",
            "metadata value":({ "first", "second" })
        ])
    ]);
    ExpectTrue(Service.matchesObservation(observation, ([
        "shared":0,
        "context value":"snow",
        "metadata value":({ "second" })
    ])));
    ExpectFalse(Service.matchesObservation(observation, ([ "shared":1 ])));
    ExpectFalse(Service.matchesObservation(observation, ([ "shared":2 ])));
    ExpectFalse(Service.matchesObservation(observation, ([
        "context value":"rain"
    ])));
    ExpectFalse(Service.matchesObservation(observation, ([ "missing":0 ])));
}

/////////////////////////////////////////////////////////////////////////////
void MatcherNormalizesObjectsAndSupportsNestedCriteria()
{
    mapping result = Service.normalizeObservation(([
        "type": "combat.kata",
        "actor": Actor,
        "subject": Actor,
        "context": ([ "conditions": ([ "weather": "snow" ]) ])
    ]));
    ExpectTrue(Service.matchesObservation(result, ([
        "type": "combat",
        "subject": Actor,
        "conditions": ([ "weather": "snow" ])
    ])));
    ExpectFalse(Service.matchesObservation(result, ([
        "conditions": ([ "weather": "rain" ])
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void RecordObservationEnrichesDefaults()
{
    mapping observation = Service.recordObservation(Actor, ([
        "type": "combat.kill",
        "actor": Actor,
        "subject": "orc marauder"
    ]));

    ExpectEq("combat.kill", observation["type"]);
    ExpectEq("/lib/tests/support/environment/fakeEnvironment.c",
        observation["location"]);
    ExpectTrue(observation["timestamp"] > 0);
    ExpectEq(sprintf("%s#%s", program_name(Actor), Actor.Name()),
        observation["actor"]);
}

/////////////////////////////////////////////////////////////////////////////
void InvalidObservationIsRejected()
{
    ExpectFalse(Service.recordObservation(0, ([ "type": "combat.kill" ])));
    ExpectFalse(Service.recordObservation(Actor, ([ "type": "" ])));
    ExpectEq(0, Actor.countObservations(([])));
}

/////////////////////////////////////////////////////////////////////////////
void QueryNormalizesObjectCriteria()
{
    Actor.recordObservation(([
        "type": "combat.kata",
        "actor": Actor,
        "subject": Actor,
        "participants": ({ Actor }),
        "context": ([ "teacher": Actor ])
    ]));

    ExpectEq(1, Actor.countObservations(([
        "actor": Actor,
        "subject": Actor,
        "participants": ({ Actor }),
        "context": ([ "teacher": Actor ])
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void RecordedObservationIsImmutable()
{
    mapping context = ([ "weather": "snow" ]);
    mapping metadata = ([ "damage": 10 ]);
    context["conditions"] = ([ "wind": "north" ]);
    metadata["details"] = ([ "source": "critical" ]);

    mapping recorded = Service.recordObservation(Actor, ([
        "type": "combat.kill",
        "actor": Actor,
        "subject": "orc",
        "context": context,
        "metadata": metadata
    ]));

    context["weather"] = "rain";
    context["conditions"]["wind"] = "south";
    metadata["damage"] = 99;
    metadata["details"]["source"] = "ordinary";
    recorded["context"]["conditions"]["wind"] = "west";
    recorded["metadata"]["details"]["source"] = "modified result";

    mapping *result = Actor.queryObservations(([]));
    ExpectEq("snow", result[0]["context"]["weather"]);
    ExpectEq(10, result[0]["metadata"]["damage"]);
    ExpectEq("north", result[0]["context"]["conditions"]["wind"]);
    ExpectEq("critical", result[0]["metadata"]["details"]["source"]);

    result[0]["context"]["conditions"]["wind"] = "east";
    result[0]["metadata"]["details"]["source"] = "changed";

    mapping *stored = Actor.queryObservations(([]));
    ExpectEq("north", stored[0]["context"]["conditions"]["wind"]);
    ExpectEq("critical", stored[0]["metadata"]["details"]["source"]);
}

/////////////////////////////////////////////////////////////////////////////
void QuerySupportsHierarchicalTypeAndContext()
{
    Actor.recordObservation(([
        "type": "combat.kill",
        "actor": Actor,
        "subject": "orc",
        "context": ([ "weapon": "katana" ])
    ]));

    Actor.recordObservation(([
        "type": "combat.parry",
        "actor": Actor,
        "subject": "orc",
        "context": ([ "weapon": "katana" ])
    ]));

    Actor.recordObservation(([
        "type": "movement.enter",
        "actor": Actor,
        "subject": "forest",
        "context": ([ "terrain": "forest" ])
    ]));

    mapping *results = Actor.queryObservations(([
        "type": "combat",
        "weapon": "katana"
    ]));

    ExpectEq(2, sizeof(results));
}

/////////////////////////////////////////////////////////////////////////////
void CountAndHasObservationWorkForQueries()
{
    Actor.recordObservation(([
        "type": "conversation.greet",
        "actor": Actor,
        "subject": "galadhel",
        "metadata": ([ "response": "accept" ])
    ]));

    ExpectEq(1, Actor.countObservations(([
        "type": "conversation.greet",
        "response": "accept"
    ])));

    ExpectTrue(Actor.hasObservation(([
        "type": "conversation",
        "response": "accept"
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void AggregationsUpdateFromRecordedObservations()
{
    Actor.recordObservation(([
        "type": "combat.kill",
        "actor": Actor,
        "subject": "orc",
        "context": ([ "weapon": "katana" ])
    ]));

    Actor.recordObservation(([
        "type": "combat.kill",
        "actor": Actor,
        "subject": "goblin",
        "context": ([ "weapon": "katana" ])
    ]));

    Actor.recordObservation(([
        "type": "movement.enter",
        "actor": Actor,
        "subject": "forest",
        "context": ([ "weapon": "staff" ])
    ]));

    ExpectEq(2, Actor.countExperiencedType("combat.kill"));
    ExpectEq(2, Actor.countExperiencedType("combat"));
    ExpectEq(2, Actor.countObservations(([ "weapon":"katana" ])));
    ExpectEq(3, Actor.countObservations(([])));
}

/////////////////////////////////////////////////////////////////////////////
void ThresholdQueriesReturnOnlyTheRequestedDecision()
{
    Actor.recordObservation(([
        "type": "combat.attack",
        "actor": Actor,
        "context": ([ "weapon": "katana" ])
    ]));

    ExpectTrue(Actor.hasObservation(([ "weapon":"katana" ]), 1));
    ExpectFalse(Actor.hasObservation(([ "weapon":"katana" ]), 2));
}

/////////////////////////////////////////////////////////////////////////////
void RemovedGlobalApisAreAbsent()
{
    foreach(string name in ({ "allObservations", "observationsFor",
        "summaryFor", "resetActor", "reset", "countByType",
        "mostFrequentContextValue" }))
    {
        ExpectFalse(function_exists(name, Service));
    }
}

/////////////////////////////////////////////////////////////////////////////
void MidnightWindowIncludesCircularBoundaries()
{
    mapping criteria = ([
        "time window": ([ "center":0, "minutes":60 ])
    ]);
    foreach(int minutes in ({ 0, 1, 60, 1380, 1439 }))
    {
        ExpectTrue(Service.matchesObservation(([
            "context": ([ "minutes after midnight":minutes ])
        ]), criteria));
    }
    foreach(int minutes in ({ 61, 720, 1379 }))
    {
        ExpectFalse(Service.matchesObservation(([
            "context": ([ "minutes after midnight":minutes ])
        ]), criteria));
    }
    ExpectTrue(Service.matchesObservation(([
        "context": ([ "minutes after midnight":1439.5 ])
    ]), ([ "time window": ([ "center":0.0, "minutes":0.5 ]) ])));
    ExpectTrue(Service.matchesObservation(([
        "context": ([ "minutes after midnight":0 ])
    ]), ([ "time window": ([ "center":1439, "minutes":1 ]) ])));
    ExpectTrue(Service.matchesObservation(([
        "context": ([ "minutes after midnight":720 ])
    ]), ([ "time window": ([ "center":0, "minutes":720 ]) ])));
}

/////////////////////////////////////////////////////////////////////////////
void MalformedWindowsAndHistoricalMinutesFailSafely()
{
    foreach(mixed window in ({ 0, "midnight", ({ 0, 60 }), ([]),
        ([ "center":0 ]), ([ "minutes":60 ]),
        ([ "center":"0", "minutes":60 ]),
        ([ "center":0, "minutes":"60" ]),
        ([ "center":-1, "minutes":60 ]),
        ([ "center":1440, "minutes":60 ]),
        ([ "center":0, "minutes":-1 ]),
        ([ "center":0, "minutes":721 ]),
        ([ "center":0, "minutes":60, "extra":1 ]) }))
    {
        ExpectFalse(Service.matchesObservation(([
            "context": ([ "minutes after midnight":0 ])
        ]), ([ "time window":window ])));
    }
    foreach(mixed minutes in ({ "0", -1, 1440, ([]), ({ }) }))
    {
        ExpectFalse(Service.matchesObservation(([
            "context": ([ "minutes after midnight":minutes ])
        ]), ([ "time window": ([ "center":0, "minutes":60 ]) ])));
    }
    ExpectFalse(Service.matchesObservation(([]), ([
        "time window": ([ "center":0, "minutes":60 ])
    ])));
    ExpectFalse(Service.matchesObservation(([ "context":([]) ]), ([
        "time window": ([ "center":0, "minutes":60 ])
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void TimestampRangesAreInclusiveAndValidated()
{
    mapping observation = ([ "timestamp":100 ]);
    ExpectTrue(Service.matchesObservation(observation, ([
        "since":100, "until":100
    ])));
    ExpectTrue(Service.matchesObservation(observation, ([ "since":99 ])));
    ExpectTrue(Service.matchesObservation(observation, ([ "until":101 ])));
    foreach(mapping criteria in ({
        ([ "since":101 ]), ([ "until":99 ]),
        ([ "since":101, "until":99 ]),
        ([ "since":-1 ]), ([ "until":-1 ]),
        ([ "since":"100" ]), ([ "until":100.0 ]),
        ([ "since":([]) ]) }))
    {
        ExpectFalse(Service.matchesObservation(observation, criteria));
    }
    ExpectFalse(Service.matchesObservation(([]), ([ "since":0 ])));
}

/////////////////////////////////////////////////////////////////////////////
void ListQueryApisAreAbsent()
{
    foreach(string method in ({ "queryObservations", "countObservations",
        "hasObservation", "summarizeObservations" }))
    {
        ExpectFalse(function_exists(method, Service));
    }
}
