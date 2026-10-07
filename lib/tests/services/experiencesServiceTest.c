//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Service;
object Actor;

void Setup()
{
    Service = clone_object("/lib/services/experiencesService.c");
    Actor = clone_object("/lib/realizations/monster.c");
    Actor.Name("Observation actor");
    move_object(Actor, "/lib/tests/support/environment/fakeEnvironment.c");
}

void CleanUp()
{
    destruct(Actor);
    destruct(Service);
}

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
void ObservationIDIsAStableDatabaseGuid()
{
    mapping first = Service.normalizeObservation(([
        "type": "combat.kata",
        "actor": Actor
    ]));
    mapping second = Service.normalizeObservation(([
        "type": "combat.kata",
        "actor": Actor
    ]));
    string *segments = explode(first["ID"], "-");
    ExpectEq(({ 8, 4, 4, 4, 12 }), map(segments, (: sizeof($1) :)));
    ExpectEq(1, sizeof(regexp(({ first["ID"] }), "^[0-9a-f-]+$")));
    ExpectTrue(first["ID"] != second["ID"]);
    ExpectEq(first["ID"], Service.normalizeObservation(first)["ID"]);
    ExpectFalse(member(first, "_observationId"));
}

void ExplicitModuleRecordingDoesNotCreateServiceHistory()
{
    ExpectTrue(Service.recordObservation(Actor, ([
        "type": "combat.kata"
    ])));
    ExpectEq(1, Actor.countObservations(([])));
    ExpectEq(0, Service.countObservations(({ }), ([])));
}

void SummaryIsDerivedWithoutStoringHistory()
{
    mapping observation = Service.normalizeObservation(([
        "type": "combat.kata",
        "actor": Actor,
        "context": ([ "weapon": "katana" ])
    ]));
    mapping summary = Service.summarizeObservations(({ observation }));
    ExpectEq(1, summary["total"]);
    ExpectEq(1, summary["context"]["weapon"]["katana"]);
    summary["context"]["weapon"]["katana"] = 99;
    ExpectEq(1, Service.summarizeObservations(({ observation }))["total"]);
    ExpectEq(0, Actor.countObservations(([])));
}

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
    ExpectEq(0, sizeof(Actor.experiencesLog()));
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

    ExpectEq(1, Service.countObservations(Actor.experiencesLog(), ([
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

    Service.recordObservation(Actor, ([
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

    mapping *result = Actor.experiencesLog();
    ExpectEq("snow", result[0]["context"]["weather"]);
    ExpectEq(10, result[0]["metadata"]["damage"]);
    ExpectEq("north", result[0]["context"]["conditions"]["wind"]);
    ExpectEq("critical", result[0]["metadata"]["details"]["source"]);

    result[0]["context"]["conditions"]["wind"] = "east";
    result[0]["metadata"]["details"]["source"] = "changed";

    mapping *stored = Actor.experiencesLog();
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

    mapping *results = Service.queryObservations(Actor.experiencesLog(), ([
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

    ExpectEq(1, Service.countObservations(Actor.experiencesLog(), ([
        "type": "conversation.greet",
        "response": "accept"
    ])));

    ExpectTrue(Service.hasObservation(Actor.experiencesLog(), ([
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
    ExpectEq("katana",
        Actor.mostFrequentExperiencedContext("weapon"));

    mapping summary = Actor.experiencesSummary();
    ExpectEq(3, summary["total"]);
}

/////////////////////////////////////////////////////////////////////////////
void SummaryCannotMutateOwnerObservations()
{
    Actor.recordObservation(([
        "type": "combat.attack",
        "actor": Actor,
        "context": ([ "weapon": "katana" ])
    ]));

    mapping summary = Actor.experiencesSummary();
    summary["context"]["weapon"]["katana"] = 99;

    ExpectEq(1, Actor.experiencesSummary()["context"]["weapon"]["katana"]);
    ExpectEq("katana", Actor.mostFrequentExperiencedContext("weapon"));
}

void RemovedGlobalApisAreAbsent()
{
    foreach(string name in ({ "allObservations", "observationsFor",
        "summaryFor", "resetActor", "reset", "countByType",
        "mostFrequentContextValue" }))
    {
        ExpectFalse(function_exists(name, Service));
    }
}

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

void ListQueriesArePureDeepCopiesAndRejectInvalidCriteria()
{
    mapping *observations = ({ ([
        "type":"combat.kata",
        "context": ([ "details": ([ "stances": ({ "tiger" }) ]) ]),
        "extra": ([ "values": ({ 1 }) ])
    ]) });
    mapping *result = Service.queryObservations(observations, ([]));
    result[0]["context"]["details"]["stances"][0] = "crane";
    result[0]["extra"]["values"][0] = 2;
    ExpectEq("tiger", observations[0]["context"]["details"]["stances"][0]);
    ExpectEq(1, observations[0]["extra"]["values"][0]);
    ExpectEq(1, Service.countObservations(observations, ([])));
    ExpectTrue(Service.hasObservation(observations, ([])));
    ExpectEq(0, sizeof(Service.queryObservations(observations, 0)));
    ExpectEq(0, Service.countObservations(observations, 0));
    ExpectFalse(Service.hasObservation(observations, 0));
    ExpectEq(0, Service.countObservations(0, ([])));
    ExpectFalse(Service.hasObservation(0, ([])));
}