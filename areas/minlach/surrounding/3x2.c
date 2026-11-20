//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addDecorator("village garden");
    setShortDescription("The common threshing margin");
    addFeature("/lib/environment/features/plants/common-grain-strips.c",
        "east");
    addItem("/lib/environment/items/objects/hay-bale.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/minlach/surrounding/3x1.c");
    addExit("west", "/areas/minlach/surrounding/2x2.c");
    addExit("north", "/areas/minlach/surrounding/3x3.c");
}
