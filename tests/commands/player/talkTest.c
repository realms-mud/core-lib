//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Target;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->Gorthaur());

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("gorthaur");
    Player->Race("human");
    Player->reset();

    Target = clone_object("/lib/tests/support/conversations/testNPC.c");
    Target->resetConversationState();
    Target->reset();

    move_object(Player, this_object());
    move_object(Target, this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Target);
}

/////////////////////////////////////////////////////////////////////////////
void TalkToTargetInitiatesConversation()
{
    ExpectTrue(Player->executeCommand("talk to fred"));
    ExpectSubStringMatch("We start talking for the first time.*1.*OK", 
        implode(Player->caughtMessages(), " "));
}

/////////////////////////////////////////////////////////////////////////////
void TalkTargetInitiatesConversation()
{
    ExpectTrue(Player->executeCommand("talk fred"));
    ExpectSubStringMatch("We start talking for the first time.*1.*OK",
        implode(Player->caughtMessages(), " "));
}

/////////////////////////////////////////////////////////////////////////////
void TalkWithoutTargetInitiatesConversation()
{
    ExpectTrue(Player->executeCommand("talk"));
    ExpectSubStringMatch("We start talking for the first time.*1.*OK",
        implode(Player->caughtMessages(), " "));
}

/////////////////////////////////////////////////////////////////////////////
void RepeatWillRepeatConversation()
{
    ExpectTrue(Player->executeCommand("talk fred"));
    ExpectSubStringMatch("We start talking for the first time.*1.*OK",
        implode(Player->caughtMessages(), " "));

    Player->resetCatchList();
    ExpectFalse(Player->caughtMessage());
    ExpectTrue(Player->executeCommand("repeat fred"));
    ExpectSubStringMatch("We start talking for the first time.*1.*OK",
        implode(Player->caughtMessages(), " "));
}

/////////////////////////////////////////////////////////////////////////////
void CanTraverseConversationTree()
{
    command("talk to fred", Player);
    ExpectSubStringMatch("We start talking for the first time.*1.*OK",
        implode(Player->caughtMessages(), " "));

    Player->resetCatchList();
    command("1", Player);
    ExpectSubStringMatch("Then let's talk", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanTraverseConversationSecondTimeWithDifferentConversation()
{
    command("talk to fred", Player);
    command("1", Player);
    command("1", Player);
    Player->resetCatchList();

    command("talk to fred", Player);
    command("2", Player);
    ExpectSubStringMatch("A bitterly frigid chill emanates from the thing", 
        implode(Player->caughtMessages(), " "));
}
