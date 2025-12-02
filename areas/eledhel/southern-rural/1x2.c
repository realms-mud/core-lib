//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("north", "/areas/eledhel/southern-rural/1x3.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("west", "/areas/eledhel/southern-rural/0x2.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
}

