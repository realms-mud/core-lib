//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("east", "/areas/eledhel/southern-rural/1x7.c");
    addFeature("/lib/environment/features/paths/road.c", "east");

    addExit("west", "/areas/eledhel/southwest-rural-one/24x0.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
}
