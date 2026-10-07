//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Actor;
object Other;

void Setup()
{
    Actor = clone_object("/lib/realizations/monster.c");
    Other = clone_object("/lib/realizations/monster.c");
    Actor.Name("Bob");
    Other.Name("Bob");
}

void CleanUp()
{
    destruct(Actor);
    destruct(Other);
}

void ObservationLogBelongsToModuleInstance()
{
    ExpectTrue(Actor.has("experiences"));
    ExpectFalse(Actor.has("experience"));
    ExpectFalse(function_exists("recordExperience", Actor));
    ExpectFalse(function_exists("queryExperience", Actor));
    ExpectFalse(function_exists("countExperience", Actor));
    ExpectFalse(function_exists("hasExperience", Actor));
    Actor.recordObservation(([ "type": "combat.kata" ]));
    ExpectEq(1, Actor.countObservations(([ "type": "combat.kata" ])));
    ExpectEq(0, Other.countObservations(([])));
    ExpectFalse(Actor.recordObservation(([
        "type": "combat.kata",
        "actor": Other
    ])));
    ExpectEq(1, Actor.countObservations(([])));
}

void InvalidFieldsAreRejected()
{
    ExpectFalse(Actor.recordObservation(([
        "type": "combat.kata",
        "context": "invalid"
    ])));
    ExpectFalse(Actor.recordObservation(([
        "type": "combat.kata",
        "timestamp": -1
    ])));
    ExpectEq(0, Actor.countObservations(([])));
}

void QueryReturnsIndependentSnapshots()
{
    Actor.recordObservation(([
        "type": "combat.kata",
        "subject": Other,
        "location": Actor,
        "context": ([ "target race": "orc", "weapon": "katana" ])
    ]));
    mapping *result = Actor.queryObservations(([ "subject": Other ]));
    ExpectEq(1, sizeof(result));
    ExpectEq(program_name(Actor), result[0]["location"]);
    result[0]["context"]["weapon"] = "staff";
    ExpectTrue(Actor.hasObservation(([ "weapon": "katana" ])));
    ExpectEq(1, Actor.experiencesSummary()["total"]);
    ExpectEq("katana", Actor.mostFrequentExperiencedContext("weapon"));
}

void PluralServiceRecordsOnOwningModule()
{
    ExpectFalse(getService("experience"));
    ExpectTrue(getService("experiences")->recordObservation(Actor, ([
        "type": "combat.kata"
    ])));
    ExpectEq(1, Actor.countObservations(([])));
    ExpectEq(0, Other.countObservations(([])));
}

void CombatKillCapturesTargetContext()
{
    Other.Race("orc");
    Other.effectiveLevel(8);
    Actor.generateCombatStatistics(Other);
    mapping *result = Actor.queryObservations(([
        "type": "combat.kill",
        "target race": "orc",
        "subject": Other
    ]));
    ExpectEq(1, sizeof(result));
    ExpectEq("Bob", result[0]["context"]["target name"]);
    ExpectEq(8, result[0]["context"]["target level"]);
    ExpectTrue(member(result[0]["context"], "moon phase"));
    ExpectEq(0, Actor.countObservations(([ "type": "combat.hit" ])));
}

void HierarchicalCandidatesMatchOnlyCompletePrefixes()
{
    foreach(string type in ({ "COMBAT.KATA.TIGER", "combat.kata.crane",
        "combat", "combatant", "combat.katapult", "movement.enter" }))
    {
        Actor.recordObservation(([ "type":type ]));
    }
    ExpectEq(4, Actor.countObservations(([ "type":"COMBAT" ])));
    ExpectEq(2, Actor.countObservations(([ "type":"combat.kata" ])));
    ExpectEq(1, Actor.countObservations(([ "type":"combat.kata.tiger" ])));
    ExpectEq(0, Actor.countObservations(([ "type":"combat.kat" ])));
    ExpectEq(0, Actor.countObservations(([ "type":"" ])));
    ExpectEq(0, Actor.countObservations(([ "type":42 ])));
    ExpectFalse(Actor.hasObservation(([ "type":"missing" ])));
    ExpectEq(6, Actor.countObservations(([])));
    ExpectEq(0, Actor.countObservations(0));
    ExpectFalse(Actor.hasObservation(0));
    ExpectEq(0, sizeof(Actor.queryObservations(0)));
}

void IndexedQueriesCombineHistoricalWindowRangeAndNestedFilters()
{
    foreach(int minutes in ({ 60, 61, 1380, 1379 }))
    {
        Actor.recordObservation(([
            "type":"combat.kata.tiger",
            "timestamp":100,
            "context": ([
                "minutes after midnight":minutes,
                "conditions": ([ "weather":"snow" ])
            ]),
            "metadata": ([ "outcome":"success" ])
        ]));
    }
    mapping criteria = ([
        "type":"COMBAT.KATA",
        "time window": ([ "center":0, "minutes":60 ]),
        "since":100,
        "until":100,
        "conditions": ([ "weather":"SNOW" ]),
        "outcome":"success"
    ]);
    ExpectEq(2, Actor.countObservations(criteria));
    ExpectEq(2, sizeof(Actor.queryObservations(criteria)));
    ExpectTrue(Actor.hasObservation(criteria));
    ExpectEq(2, getService("experiences")->countObservations(
        Actor.experiencesLog(), criteria));
    criteria["until"] = 99;
    ExpectEq(0, Actor.countObservations(criteria));
    ExpectFalse(Actor.hasObservation(criteria));
    criteria["until"] = 100;
    criteria["conditions"]["weather"] = "rain";
    ExpectEq(0, Actor.countObservations(criteria));
}

void IndexedOutputsCannotMutateStoredCandidates()
{
    mapping result = Actor.recordObservation(([
        "type":"combat.kata.tiger",
        "context": ([ "details": ([ "stances": ({ "tiger" }) ]) ])
    ]));
    result["type"] = "movement.enter";
    result["context"]["details"]["stances"][0] = "crane";
    mapping *snapshot = Actor.queryObservations(([ "type":"combat" ]));
    snapshot[0]["type"] = "movement.enter";
    snapshot[0]["context"]["details"]["stances"][0] = "crane";
    ExpectEq(1, Actor.countObservations(([
        "type":"combat.kata",
        "details": ([ "stances": ({ "tiger" }) ])
    ])));
    ExpectEq(0, Actor.countObservations(([ "type":"movement" ])));
}

void RestoreRebuildsIndexAndDatabaseQueriesUseSameMatcher()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();
    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    mapping data = database.Gorthaur();
    data["experiences"] += ({ ([
        "ID":generateGuid(),
        "type":"combat.kata.tiger",
        "actor":"/lib/realizations/player#gorthaur",
        "subject":"orc",
        "participants": ({ }),
        "timestamp":100,
        "location":"temple",
        "context": ([ "minutes after midnight":1380, "weapon":"katana" ]),
        "metadata": ([ "outcome":"success" ])
    ]) });
    dataAccess.savePlayerData(data);
    object player = clone_object("/lib/realizations/player.c");
    player.recordObservation(([ "type":"movement.enter" ]));
    player.restore("gorthaur");
    ExpectEq(0, player.countObservations(([ "type":"movement" ])));
    ExpectEq(2, player.countObservations(([ "type":"combat" ])));
    mapping criteria = ([
        "type":"combat.kata",
        "time window": ([ "center":0, "minutes":60 ]),
        "since":100,
        "until":100,
        "weapon":"KATANA",
        "outcome":"success"
    ]);
    ExpectEq(1, player.countObservations(criteria));
    ExpectEq(player.queryObservations(criteria),
        dataAccess.queryObservationsByPlayer("gorthaur", criteria, 0, 0));
    criteria["time window"]["minutes"] = "invalid";
    ExpectEq(0, player.countObservations(criteria));
    ExpectEq(0, dataAccess.countObservationsByPlayer("gorthaur", criteria));
    ExpectEq(0, dataAccess.countObservationsByPlayer("gorthaur", 0));
    player.recordObservation(([ "type":"research.learn" ]));
    player.restore("gorthaur");
    ExpectEq(0, player.countObservations(([ "type":"research" ])));
    ExpectEq(2, player.countObservations(([ "type":"combat" ])));
    destruct(player);
    destruct(dataAccess);
    destruct(database);
}