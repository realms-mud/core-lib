//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Player.Name("ralph");
    Player.Race("elf");
    Player.addCommands();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerSeesMessageWhenMapNotAvailable()
{
    Player.colorConfiguration("none");
    object unmappedRoom =
        clone_object("/lib/tests/support/environment/startingRoom.c");

    move_object(Player, unmappedRoom);

    command("map", Player);

    ExpectEq("There is no map available for this area.\n", Player.caughtMessage());

    destruct(unmappedRoom);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerSeesMapWhenInSupportedRegion()
{
    Player.colorConfiguration("none");
    object mappedRoom =
        load_object("/lib/tests/support/environment/regionRoom.c");

    mappedRoom.addGeneratedRegion("north", "forest", 5, 5);

    move_object(Player, mappedRoom);

    command("n", Player);
    command("map", Player);

    // This should be 241 (5 x 5 x 9 + 16 '\n' characters)
    // Since it's randomly-generated, we can't verify the map by drawing it
    ExpectEq(241, sizeof(Player.caughtMessage()));

    destruct(mappedRoom);
}
