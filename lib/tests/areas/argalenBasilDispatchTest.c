//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Owner;
object Conversation;
object Room;
string TolDhurathQuest =
    "/areas/tol-dhurath/state-machine/tol-dhurath-quest.c";
string RoadMeasureQuest = "/areas/minlach/quests/road-measure.c";

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("argalenbasiltest");
    set_this_player(Player);
    Room = load_object("/lib/tests/support/environment/fakeEnvironment.c");
    move_object(Player, Room);

    Owner = clone_object(
        "/areas/argalen-keep/characters/lord-argalen/lord-argalen.c");
    move_object(Owner, Room);
    Conversation = load_object(
        "/areas/argalen-keep/characters/lord-argalen/startingConversation.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(Owner))
    {
        destruct(Owner);
    }
    if (objectp(Player))
    {
        destruct(Player);
    }
}

/////////////////////////////////////////////////////////////////////////////
void LordWithholdsTheDispatchUntilTheTrialIsComplete()
{
    Conversation->speakMessage("first conversation", Player, Owner);
    ExpectEq(0, sizeof(Conversation->responses(Player)));
}

/////////////////////////////////////////////////////////////////////////////
void LordOpensTheDispatchAfterTheTrialIsComplete()
{
    object quest = load_object(TolDhurathQuest);
    ExpectTrue(Player->beginQuest(TolDhurathQuest));
    ExpectTrue(quest->receiveEvent(Player, "met maiwyn"));
    ExpectTrue(quest->receiveEvent(Player, "maiwyn helps"));
    ExpectTrue(quest->receiveEvent(Player, "obedience trial complete"));
    ExpectEq("trial complete", Player->questState(TolDhurathQuest));
    ExpectTrue(Player->questIsCompleted(TolDhurathQuest));

    ExpectTrue(Conversation->speakMessage(
        "first conversation", Player, Owner));
    ExpectEq(1, sizeof(Conversation->responses(Player)));
}

/////////////////////////////////////////////////////////////////////////////
void BasilWithholdsFinalDecisionsUntilTheRoadSurveyIsReady()
{
    object tolDhurath = load_object(TolDhurathQuest);
    object roadMeasure = load_object(RoadMeasureQuest);
    object yard = load_object("/areas/minlach/0x3.c");
    object basil = clone_object("/areas/minlach/characters/basil/basil.c");
    object basilConversation = load_object(
        "/areas/minlach/characters/basil/startingConversation.c");
    move_object(Player, yard);
    move_object(basil, yard);

    ExpectTrue(Player->beginQuest(TolDhurathQuest));
    ExpectTrue(tolDhurath->receiveEvent(Player, "met maiwyn"));
    ExpectTrue(tolDhurath->receiveEvent(Player, "maiwyn helps"));
    ExpectTrue(tolDhurath->receiveEvent(Player, "obedience trial complete"));
    ExpectTrue(Player->questIsCompleted(TolDhurathQuest));
    ExpectTrue(Player->beginQuest(RoadMeasureQuest));

    basilConversation->speakMessage("first conversation", Player, basil);
    ExpectEq(1, sizeof(basilConversation->responses(Player)));
    ExpectTrue(roadMeasure->receiveEvent(Player, "checkWaystations"));
    ExpectTrue(roadMeasure->receiveEvent(Player, "checkTownWatch"));
    ExpectTrue(roadMeasure->receiveEvent(Player, "checkAvailableStores"));
    ExpectTrue(roadMeasure->receiveEvent(Player, "reportRoadMeasures"));
    basilConversation->speakMessage("first conversation", Player, basil);
    ExpectEq(2, sizeof(basilConversation->responses(Player)));
    destruct(basil);
}

/////////////////////////////////////////////////////////////////////////////
void BasilCanStartTheRoadAssessmentInTheMinlachWatchYard()
{
    object yard = load_object("/areas/minlach/0x3.c");
    object basil = clone_object("/areas/minlach/characters/basil/basil.c");
    move_object(Player, yard);
    move_object(basil, yard);

    basil->notifySynchronous("minlachBeginRoad", Player);
    ExpectTrue(Player->questIsActive(RoadMeasureQuest));
    ExpectEq("started", Player->questState(RoadMeasureQuest));
    destruct(basil);
}
