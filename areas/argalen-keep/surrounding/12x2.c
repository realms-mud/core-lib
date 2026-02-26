//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/landforms/dale.c", "east");

    addExit("south", "/areas/argalen-keep/surrounding/12x1.c");
    addExit("north", "/areas/argalen-keep/surrounding/12x3.c");
    addExit("west", "/areas/argalen-keep/surrounding/11x2.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addExit("east", "/areas/argalen-keep/surrounding/13x2.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
}
