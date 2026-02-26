//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "east");
    addFeature("/lib/environment/features/trees/walnut-stand.c", "north");
    addFeature("/lib/environment/features/water/brook.c", "south");

    addExit("west", "/areas/argalen-keep/surrounding/8x4.c");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addExit("north", "/areas/argalen-keep/surrounding/9x3.c");
    addFeature("/lib/environment/features/paths/trail.c", "north");
    addExit("south", "/areas/argalen-keep/surrounding/9x5.c");
    addFeature("/lib/environment/features/paths/trail.c", "south");
}
