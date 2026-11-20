//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-west");
    setShortDescription("The waterfall bend");
    addFeature("/lib/environment/features/water/brook.c", "east");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addExit("north", "/areas/eledhel/west-rural-two/10x3.c");
    addExit("west", "/areas/eledhel/west-rural-two/9x2.c");
}
