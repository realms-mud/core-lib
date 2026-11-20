//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior south-east corner hallway");
    setShortDescription("The relay tower's store cellar");
    addItem("/lib/environment/items/furniture/tall-shelf.c", "west");
    addItem("/lib/environment/items/records/ledger-desk.c", "north");
    addItem("/lib/environment/items/lighting/lantern.c", "east");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c",
        "none");
    addClue("tower ledger", "watchtowers-names", "readTowerLedger",
        "The ledger records wages, local household names, "
        "and contributions to a common watchtower repair fund.");
    addExitWithDoor("east", "/areas/minlach/surrounding/1x6.c",
        "/lib/environment/doors/plank-door.c");
    addExitWithDoor("south", "/areas/minlach/surrounding/0x5.c",
        "/lib/environment/doors/plank-door.c");
}
