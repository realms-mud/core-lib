//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("west", "/areas/eledhel/southwest-rural-one/2x3.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addExit("north", "/areas/eledhel/southwest-rural-one/3x4.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
}
