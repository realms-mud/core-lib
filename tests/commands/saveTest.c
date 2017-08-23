//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    setRestoreCaller(this_object());
    Player->Name("bob");
    Player->Race("human");
    Player->addCommands();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerSavedWhenSaveIsCalled()
{
    object persistedPlayer = clone_object("/lib/realizations/player.c");
    persistedPlayer->restore("bob");
    ExpectEq(0, persistedPlayer->Race());

    ExpectTrue(Player->executeCommand("save"));
    ExpectEq("Saving character...\n", Player->caughtMessage());

    persistedPlayer = clone_object("/lib/realizations/player.c");
    persistedPlayer->restore("bob");
    ExpectEq("human", persistedPlayer->Race());
    destruct(persistedPlayer);
}

