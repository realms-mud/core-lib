//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("west", "/areas/eledhel/southwest-rural-one/9x4.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addExit("south", "/areas/eledhel/southwest-rural-one/10x3.c");
    addFeature("/lib/environment/features/paths/road.c", "south");
}
