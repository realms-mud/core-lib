//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-west");
    setShortDescription("The split-root den");

    addFeature("/lib/environment/features/water/brook.c", "southwest");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addItem("/lib/environment/items/objects/fox-tracks.c", "northwest");

    addExit("south", "/areas/eledhel/west-rural-two/7x2.c");
    addExit("north", "/areas/eledhel/west-rural-two/7x4.c");
    addExit("west", "/areas/eledhel/west-rural-two/6x3.c");
    addExit("down", "/areas/eledhel/west-rural-two/fox-den/0x0.c");
}
