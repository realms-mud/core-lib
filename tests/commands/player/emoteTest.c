//*****************************************************************************
// Copyright (c) 2018 -Allen Cummings, RealmsMUD, All rights reserved. See
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
    Player->Gender(1);
    Player->addCommands();
    move_object(Player, this_object());

    Bystander = clone_object("/lib/tests/support/services/mockPlayer.c");
    Bystander->Name("frank");
    Bystander->Race("human");
    Bystander->addCommands();
    move_object(Bystander, this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Bystander);
}

/////////////////////////////////////////////////////////////////////////////
void EmoteDisplaysCorrectMessage()
{
    ExpectTrue(Player->executeCommand("emote does stuff."));
    ExpectEq("Bob does stuff.\n", Player->caughtMessage());
    ExpectEq("Bob does stuff.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ColonDisplaysCorrectMessage()
{
    ExpectTrue(Player->executeCommand(":does stuff."));
    ExpectEq("Bob does stuff.\n", Player->caughtMessage());
    ExpectEq("Bob does stuff.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EmoteNukesEscapeCharacters()
{
    ExpectTrue(Player->executeCommand(":\x1bd\x1bo\x1b\x1b\x1b\x1b\x1b\x1b\x1b\x1be\x1bs\x1b \x1bs\x1bt\x1bu\x1bf\x1bf."));
    ExpectEq("Bob does stuff.\n", Player->caughtMessage());
    ExpectEq("Bob does stuff.\n", Bystander->caughtMessage());
}
