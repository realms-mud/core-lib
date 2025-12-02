//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.Gorthaur());

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.Race("human");
    Player.addCommands();
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
    persistedPlayer.restore("bob");
    ExpectEq(0, persistedPlayer.Race());
    destruct(persistedPlayer);

    ExpectTrue(Player.executeCommand("save"));
    ExpectEq("Saving character...\n", Player.caughtMessage());

    persistedPlayer = clone_object("/lib/realizations/player.c");
    persistedPlayer.restore("bob");
    ExpectEq("human", persistedPlayer.Race());
    destruct(persistedPlayer);
}

