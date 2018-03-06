//*****************************************************************************
// Copyright (c) 2018 -Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->Race("human");
    Player->Gender(1);
    Player->pageSize(200);
    Player->addCommands();
    move_object(Player, this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void HelpDisplaysMainHelpMenu()
{
    ExpectTrue(Player->executeCommand("help"));
    command(" ", Player);
    ExpectSubStringMatch("zing.*Interactions.*General.*save", 
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PagingDisplaysBreakRequiringInput()
{
    Player->pageSize(20);
    ExpectTrue(Player->executeCommand("help"));
    ExpectEq("\n[0;35;1mMore? [q to quit][0m\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HelpForSpecificCommandDisplaysCommandInfo()
{
    ExpectTrue(Player->executeCommand("help say"));
    ExpectSubStringMatch("Synopsis.*Syntax.*Description.*Options.*.*Notes", 
        Player->caughtMessage());
}
