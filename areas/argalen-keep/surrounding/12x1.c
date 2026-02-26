//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");
    addFeature("/lib/environment/features/trees/ash-stand.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("south", "/areas/argalen-keep/surrounding/12x0.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addExit("north", "/areas/argalen-keep/surrounding/12x2.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addExit("west", "/areas/argalen-keep/surrounding/11x1.c");
    addFeature("/lib/environment/features/paths/trail.c", "west");
    addExit("east", "/areas/argalen-keep/surrounding/13x1.c");
    addFeature("/lib/environment/features/paths/trail.c", "east");
}
