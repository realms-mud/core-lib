//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "west");
    addFeature("/lib/environment/features/water/gulley-creek.c", "northeast");

    addExit("north", "/areas/tol-dhurath/forest-3/1x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-3/0x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"hunter","outlaw","coyote","timber wolf"}));
}
