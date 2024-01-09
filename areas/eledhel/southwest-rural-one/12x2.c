//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("north", "/areas/eledhel/southwest-rural-one/12x3.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("east", "/areas/eledhel/southwest-rural-one/13x2.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
}
