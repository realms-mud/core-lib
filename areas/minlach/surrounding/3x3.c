//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("village road intersection");
    setShortDescription("The stream crossing");
    addFeature("/lib/environment/features/water/river-with-bridge.c",
        "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/minlach/surrounding/3x2.c");
    addExit("north", "/areas/minlach/surrounding/3x4.c");
    addExit("west", "/areas/minlach/surrounding/2x3.c");
    addExit("east", "/areas/minlach/surrounding/4x3.c");
}
