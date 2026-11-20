//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The common threshing yard");
    addDecorator("farm threshing yard");
    addItem("/lib/environment/items/objects/sack-pile.c", "south");
    addItem("/lib/environment/items/objects/notice-board.c", "east");
    addBuildingWithDoor("/lib/environment/buildings/trades/granary.c",
        "west", "/areas/eledhel/central-rural/20x4.c",
        "/lib/environment/doors/plank-door.c");
    addExit("east", "/areas/eledhel/central-rural/22x4.c");
    addExit("south", "/areas/eledhel/central-rural/21x3.c");
    addExit("north", "/areas/eledhel/central-rural/21x5.c");
}
