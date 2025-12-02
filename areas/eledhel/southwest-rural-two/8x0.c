//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("north", "/areas/eledhel/southwest-rural-two/8x1.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("east", "/areas/eledhel/southwest-rural-two/9x0.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
}

