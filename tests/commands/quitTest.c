//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

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
    Player = clone_object("/lib/realizations/player.c");
    Player->Name("ralph");
    Player->Race("elf");
    Player->addCommands();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerSavedAndQuitsWhenQuitIsCalled()
{
    object persistedPlayer = clone_object("/lib/realizations/player.c");
    persistedPlayer->restore("ralph");
    ExpectEq(0, persistedPlayer->Race());

    ExpectTrue(Player->executeCommand("quit"));
    ExpectFalse(objectp(Player));
    persistedPlayer = clone_object("/lib/realizations/player.c");
    persistedPlayer->restore("ralph");
    ExpectEq("elf", persistedPlayer->Race());
    destruct(persistedPlayer);
}

