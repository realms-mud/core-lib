//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Actor;

void Setup()
{
    Actor = clone_object("/lib/realizations/monster.c");
    Actor.Name("Query performance actor");
    for (int index = 0; index < 1000; index++)
    {
        Actor.recordObservation(([
            "type":index % 100 ? "movement.enter" : "combat.kata.tiger",
            "context": ([ "weapon":"katana" ])
        ]));
    }
}

void CleanUp()
{
    destruct(Actor);
}

void IndexedTypeCountUsesLessEvaluationThanFullScan()
{
    object service = getService("experiences");
    mapping criteria = ([ "type":"combat.kata", "weapon":"katana" ]);
    mapping *observations = Actor.experiencesLog();
    int start = get_eval_cost();
    int indexedCount = Actor.countObservations(criteria);
    int indexedCost = start - get_eval_cost();
    start = get_eval_cost();
    int scanCount = service->countObservations(observations, criteria);
    int scanCost = start - get_eval_cost();
    ExpectEq(10, indexedCount);
    ExpectEq(scanCount, indexedCount);
    ExpectTrue(indexedCost > 0);
    ExpectTrue(scanCost > indexedCost);
}