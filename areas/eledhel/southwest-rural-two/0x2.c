//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("east", "/areas/eledhel/southwest-rural-two/1x2.c");
    addFeature("/lib/environment/features/paths/road.c", "east");

    addExit("east", "/areas/eledhel/south-rural-route-01/0x2.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
}
