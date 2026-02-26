//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "east");
    addFeature("/lib/environment/features/trees/hazel-stand.c", "south");
    addFeature("/lib/environment/features/water/creek.c", "northeast");

    addExit("west", "/areas/argalen-keep/surrounding/12x1.c");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addExit("north", "/areas/argalen-keep/surrounding/13x2.c");
    addFeature("/lib/environment/features/paths/trail.c", "north");
}
