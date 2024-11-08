//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("east", "/areas/eledhel/southwest-rural-one/22x0.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("west", "/areas/eledhel/southwest-rural-one/20x0.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addExit("north", "/areas/eledhel/southwest-rural-one/21x1.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
}
