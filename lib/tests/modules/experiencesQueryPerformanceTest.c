//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include <object_info.h>

private object Actor;
private object Database;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "seedHistory" });
    setRestoreCaller(this_object());
    Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    Database.PrepDatabase();
    object authentication = clone_object(
        "/lib/modules/secure/dataServices/authenticationDataService.c");
    authentication.saveUser("gorthaur", "gorthaur", "127.0.0.1");
    destruct(authentication);
    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(Database.Gorthaur());
    destruct(dataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    int handle = db_connect(RealmsDatabase());
    db_exec(handle, "delete from experienceObservations;");
    string failure = db_error(handle);
    while (db_fetch(handle));
    db_close(handle);
    if (failure)
    {
        raise_error("Performance fixture failed: " + failure + "\n");
    }
    Actor = clone_object("/lib/realizations/player.c");
    Actor.restore("gorthaur");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Actor);
}

/////////////////////////////////////////////////////////////////////////////
void TearDown()
{
    destruct(Database);
}

/////////////////////////////////////////////////////////////////////////////
private void seedHistory()
{
    int handle = db_connect(RealmsDatabase());
    string digits = "(select 0 n union all select 1 union all select 2 "
        "union all select 3 union all select 4 union all select 5 "
        "union all select 6 union all select 7 union all select 8 "
        "union all select 9)";
    mapping observation = Actor.queryObservations(([]), 1, 0)[0];
    db_exec(handle, sprintf("insert into experienceObservations "
        "(playerId,observationType,actor,observationTime) select "
        "owner.playerId,'history.event','actor',0 "
        "from experienceObservations owner cross join %s a cross join %s b "
        "cross join %s c where owner.id=%d;",
        digits, digits, digits, to_int(observation["ID"])));
    if (db_error(handle))
    {
        raise_error("Performance fixture failed: " + db_error(handle) + "\n");
    }
    while (db_fetch(handle));
    db_close(handle);
}

/////////////////////////////////////////////////////////////////////////////
void RecordingDoesNotRetainObservationMappings()
{
    Actor.recordObservation(([ "type":"movement.enter" ]));
    int before = object_info(Actor, OI_DATA_SIZE_TOTAL);
    int start = get_eval_cost();
    for (int index = 0; index < 100; index++)
    {
        Actor.recordObservation(([
            "type":"movement.enter",
            "context":([ "sequence":index ])
        ]));
    }
    int cost = start - get_eval_cost();
    int after = object_info(Actor, OI_DATA_SIZE_TOTAL);
    ExpectEq(before, after, "No history is retained on the player");
    ExpectTrue(cost < 400000,
        "Recording 100 observations must use fewer than 400000 eval units");
    ExpectEq(101, Actor.countObservations(([ "type":"movement" ])));
}

/////////////////////////////////////////////////////////////////////////////
void QueryEvaluationAndPlayerMemoryDoNotGrowWithHistory()
{
    Actor.recordObservation(([ "type":"combat.kata" ]));
    mapping criteria = ([ "type":"combat" ]);
    Actor.countObservations(criteria);
    int memoryBefore = object_info(Actor, OI_DATA_SIZE_TOTAL);
    int start = get_eval_cost();
    ExpectEq(1, Actor.countObservations(criteria));
    int smallCost = start - get_eval_cost();
    seedHistory();
    start = get_eval_cost();
    ExpectEq(1, Actor.countObservations(criteria));
    int largeCost = start - get_eval_cost();
    ExpectTrue(largeCost < 10000);
    ExpectTrue(abs(largeCost - smallCost) < 1000);
    ExpectEq(memoryBefore, object_info(Actor, OI_DATA_SIZE_TOTAL));
    ExpectEq(1001, Actor.countObservations(([])));
    ExpectTrue(Actor.hasObservation(([]), 1000));
    ExpectFalse(Actor.hasObservation(([]), 1002));
    ExpectEq(100, sizeof(Actor.queryObservations(([]), 1000000)));
}

/////////////////////////////////////////////////////////////////////////////
void NpcsDoNotBuildContextOrRetainHistory()
{
    object npc = clone_object("/lib/realizations/monster.c");
    int memoryBefore = object_info(npc, OI_DATA_SIZE_TOTAL);
    int start = get_eval_cost();
    for (int index = 0; index < 1000; index++)
    {
        npc.recordObservation(([ "type":"combat.kata" ]));
    }
    int cost = start - get_eval_cost();
    ExpectTrue(cost < 100000);
    ExpectEq(memoryBefore, object_info(npc, OI_DATA_SIZE_TOTAL));
    ExpectEq(0, npc.countObservations(([])));
    ExpectFalse(npc.recordsObservations());
    destruct(npc);
}
