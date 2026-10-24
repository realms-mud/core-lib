//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/support/guilds/monkMasteryTrialFixture.c";

/////////////////////////////////////////////////////////////////////////////
void EverySeniorRouteCrossesTwentyWithRealExecutionWithoutCrossTraining()
{
    ExerciseAllRoutes(0);
}

/////////////////////////////////////////////////////////////////////////////
void EveryCandidateRouteCrossesThirtyWithRealExecutionWithoutCrossTraining()
{
    ExerciseAllRoutes(1);
}

/////////////////////////////////////////////////////////////////////////////
void KnowledgeAndPracticeMustBelongToTheSameRoute()
{
    PrepareAt(0, "unarmed", "");
    mapping unarmed = RouteFor(0, "unarmed", "");
    TeachMonkTrialLesson(User, ({ Lian, Ren }),
        "/guilds/monk/unarmed/sapping-palm.c");
    TeachMonkTrialLesson(User, ({ Lian, Ren }),
        "/guilds/monk/katana/rising-lines.c");
    AddEvidence(unarmed, 20, 1, 0);
    ExpectFalse(User.canResearch(TrialPath(0)));
    AddEvidence(RouteFor(0, "katana", ""), 19, 1, 0);
    ExpectFalse(User.canResearch(TrialPath(0)));
    TeachMonkTrialLesson(User, ({ Lian, Ren }),
        "/guilds/monk/unarmed/meridian-lore.c");
    ExpectTrue(User.canResearch(TrialPath(0)));
}

/////////////////////////////////////////////////////////////////////////////
void PartialCountsWrongEventsAndUnqualifiedUsesCannotBeCombined()
{
    PrepareAt(0, "unarmed", "");
    foreach(mapping route in Routes(0))
    {
        TeachRoute(route);
        AddEvidence(route, 19, 1, 0);
        AddEvidence(route, 25, 0, 0);
        AddEvidence(route, 25, 1,
            route["qualifying practice"]["criteria"]["type"] ==
                "combat.kata" ? "research.use" : "combat.kata");
    }
    ExpectFalse(User.canResearch(TrialPath(0)));
    ExpectFalse(User.learnResearchFrom(Ren, TrialPath(0)));
    ExpectFalse(User.advanceRank("monk"));
    AddEvidence(RouteFor(0, "claw", ""), 1, 1, 0);
    ExpectTrue(User.canResearch(TrialPath(0)));
}

/////////////////////////////////////////////////////////////////////////////
void CertificationsRequireMembershipRankLevelRecognitionAndFoundation()
{
    foreach(string trial in Trials)
    {
        ExpectFalse(User.canResearch("/guilds/monk/discipline/" +
            trial + ".c"));
    }
    PrepareAt(0, "unarmed", "");
    TeachRoute(RouteFor(0, "unarmed", ""));
    AddEvidence(RouteFor(0, "unarmed", ""), 20, 1, 0);
    ExpectTrue(User.canResearch(TrialPath(0)));
    ExpectFalse(User.canResearch(TrialPath(1)));
    ExpectFalse(User.canResearch(TrialPath(2)));
    ExpectTrue(User.demoteRank("monk"));
    ExpectFalse(User.canResearch(TrialPath(0)));
    ExpectTrue(User.advanceRank("monk"));
    ExpectTrue(User.canResearch(TrialPath(0)));
    ExpectTrue(User.leaveGuild("monk"));
    ExpectFalse(User.canResearch(TrialPath(0)));
}
