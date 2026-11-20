//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The northern road to Celedrath lands");

    addExit("north", "/areas/eledhel/southwest-rural-three/20x4.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("east", "/areas/eledhel/southwest-rural-three/21x3.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("west", "/areas/eledhel/estates/celedrath/grounds/0x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

