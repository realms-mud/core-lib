//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("A farm lane south of Eledhel");

    addExit("west", "/areas/eledhel/southern-rural/3x6.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addExit("north", "/areas/eledhel/southern-rural/4x7.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("east", "/areas/eledhel/estates/oeldhen/grounds/0x2.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
}

