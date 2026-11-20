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
    setShortDescription("The maple brook bend");
    addFeature("/lib/environment/features/trees/maple-stand.c", "southwest");
    addFeature("/lib/environment/features/water/brook.c", "southwest");

    addExit("west", "/areas/eledhel/west-rural-two/15x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/16x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"zombie","kit fox","outlaw"}));
}
