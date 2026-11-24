//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
string QuestPath = "/areas/minlach/quests/road-measure.c";

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("roadmeasuretest");
    Player->addCommands();
    set_this_player(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(Player))
    {
        destruct(Player);
    }
}

/////////////////////////////////////////////////////////////////////////////
void RoadAssessmentRequiresEachLocalRecord()
{
    object quest = load_object(QuestPath);
    ExpectTrue(Player->beginQuest(QuestPath));
    ExpectFalse(quest->receiveEvent(Player, "checkAvailableStores"));
    ExpectEq("started", Player->questState(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "checkWaystations"));
    ExpectEq("waystations checked", Player->questState(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "checkTownWatch"));
    ExpectEq("watch checked", Player->questState(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "checkAvailableStores"));
    ExpectEq("stores checked", Player->questState(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "reportRoadMeasures"));
    ExpectEq("ready", Player->questState(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "reserveStores"));
    ExpectEq("reserve stores", Player->questState(QuestPath));
}

/////////////////////////////////////////////////////////////////////////////
void RoadAssessmentCanRecommendOnlyApprovedLimitedRepairs()
{
    object quest = load_object(QuestPath);
    ExpectTrue(Player->beginQuest(QuestPath));
    ExpectTrue(quest->receiveEvent(Player, "checkWaystations"));
    ExpectTrue(quest->receiveEvent(Player, "checkTownWatch"));
    ExpectTrue(quest->receiveEvent(Player, "checkAvailableStores"));
    ExpectTrue(quest->receiveEvent(Player, "reportRoadMeasures"));
    ExpectTrue(quest->receiveEvent(Player, "acceptRoadRepair"));
    ExpectEq("limited repair", Player->questState(QuestPath));
}
