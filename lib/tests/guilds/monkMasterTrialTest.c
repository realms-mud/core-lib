//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/support/guilds/monkMasteryTrialFixture.c";

/////////////////////////////////////////////////////////////////////////////
void EveryMasterRouteCrossesFortyWithRealExecutionWithoutCrossTraining()
{
    ExerciseAllRoutes(2);
}

/////////////////////////////////////////////////////////////////////////////
void MasterCanDemonstrateAllFortyUsesWithoutSeededMasterPractice()
{
    PrepareAt(2, "unarmed", "");
    mapping route = RouteFor(2, "unarmed", "");
    TeachRoute(route);
    for (int use = 0; use < 40; use++)
    {
        ExpectFalse(User.canResearch(TrialPath(2)));
        RecoverPractice("/guilds/monk/unarmed/empty-hand.c");
        ExpectTrue(Target.registerAttacker(User));
        ExpectTrue(User.registerAttacker(Target));
        ExpectTrue(User.executeCommand("kata empty hand at opponent"));
        ExpectEq(use + 1,
            User.countObservations(route["qualifying practice"]["criteria"]));
    }
    ExpectTrue(User.canResearch(TrialPath(2)));
}
