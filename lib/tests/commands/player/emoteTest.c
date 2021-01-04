//*****************************************************************************
// Copyright (c) 2021 -Allen Cummings, RealmsMUD, All rights reserved. See
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
    Player->Gender("male");
    Player->colorConfiguration("none");
    Player->addCommands();
    move_object(Player, this_object());

    Bystander = clone_object("/lib/tests/support/services/mockPlayer.c");
    Bystander->Name("frank");
    Bystander->Race("human");
    Bystander->colorConfiguration("none");
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

/////////////////////////////////////////////////////////////////////////////
void NoneColorIsSupported()
{
    Player->colorConfiguration("3-bit");
    Bystander->colorConfiguration("none");
    ExpectTrue(Player->executeCommand(":does stuff."));
    ExpectEq("\x1b[0;36mBob does stuff.\n\x1b[0m", Player->caughtMessage());
    ExpectEq("Bob does stuff.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThreeBitColorIsSupported()
{
    Player->colorConfiguration("8-bit");
    Bystander->colorConfiguration("3-bit");
    ExpectTrue(Player->executeCommand(":does stuff."));
    ExpectEq("\x1b[0;38;5;92mBob does stuff.\n\x1b[0m", Player->caughtMessage());
    ExpectEq("\x1b[0;36mBob does stuff.\n\x1b[0m", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EightBitColorIsSupported()
{
    Player->colorConfiguration("none");
    Bystander->colorConfiguration("8-bit");
    ExpectTrue(Player->executeCommand(":does stuff."));
    ExpectEq("Bob does stuff.\n", Player->caughtMessage());
    ExpectEq("\x1b[0;38;5;92mBob does stuff.\n\x1b[0m", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwentyFourBitColorIsSupported()
{
    Player->colorConfiguration("24-bit");
    Bystander->colorConfiguration("24-bit");
    ExpectTrue(Player->executeCommand(":does stuff."));
    ExpectEq("\x1b[0;38;2;180;180;190mBob does stuff.\n\x1b[0m", Player->caughtMessage());
    ExpectEq("\x1b[0;38;2;180;180;190mBob does stuff.\n\x1b[0m", Bystander->caughtMessage());
}
