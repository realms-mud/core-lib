//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addDecorator("village east-west road");
    setShortDescription("The common granary lane");
    addBuilding("/lib/environment/buildings/trades/granary.c", "north");
    addItem("/lib/environment/items/objects/notice-board.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addClue("common stores", "warm-room", "checkCommonStores",
        "The store board reserves dried grain, roots, and fish "
        "for delayed travelers. Seed stock is listed separately.");
    addExit("east", "/areas/minlach/0x1.c");
    addExit("west", "/areas/minlach/surrounding/3x1.c");
}
