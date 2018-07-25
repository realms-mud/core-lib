//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Bystander;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->Race("human");
    Player->addCommands();
    move_object(Player, this_object());

    Bystander = clone_object("/lib/tests/support/services/mockPlayer.c");
    Bystander->Name("frank");
    Bystander->Race("human");
    Bystander->addCommands();
    move_object(Bystander, this_object());

    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    channels->registerUser(Player);
    channels->registerUser(Bystander);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Bystander);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player->executeCommand("rrace"), "rrace");
    ExpectFalse(Player->executeCommand("racee"), "racee");
}

/////////////////////////////////////////////////////////////////////////////
void CanSendMessageOnRaceLine()
{
    ExpectTrue(Player->executeCommand("race Hi"));
    ExpectSubStringMatch("Human Bob.*Hi", Player->caughtMessage());
    ExpectSubStringMatch("Human Bob.*Hi", Bystander->caughtMessage());

    ExpectTrue(Bystander->executeCommand("race Yo"));
    ExpectSubStringMatch("Human Frank.*Yo", Player->caughtMessage());
    ExpectSubStringMatch("Human Frank.*Yo", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSendEmptyMessageOnRaceLine()
{
    ExpectFalse(Player->executeCommand("race"));
    ExpectEq(0, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RaceFailsIfYourRaceIsNotSet()
{
    Player->Race("");
    ExpectFalse(Player->executeCommand("race"));
    ExpectEq(0, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSeeOtherRaceMessages()
{
    object lowlyElf = clone_object("/lib/tests/support/services/mockPlayer.c");
    lowlyElf->Name("dwight");
    lowlyElf->Race("human");
    lowlyElf->addCommands();

    ExpectTrue(Player->executeCommand("race Dwight is an idiot!"));
    ExpectSubStringMatch("Dwight is an idiot", Player->caughtMessage());
    ExpectSubStringMatch("Dwight is an idiot", Bystander->caughtMessage());
    ExpectEq(0, lowlyElf->caughtMessage());
    destruct(lowlyElf);
}

/////////////////////////////////////////////////////////////////////////////
void RaceHelpIsDisplayed()
{
    ExpectTrue(Player->executeCommand("help race"));
    ExpectSubStringMatch("Send a message to every logged-in player of your race", 
        Player->caughtMessages()[0]);
}
