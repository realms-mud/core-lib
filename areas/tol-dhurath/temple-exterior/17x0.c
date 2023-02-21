//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "west");

    addExit("north", "/areas/tol-dhurath/temple-exterior/17x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/temple-exterior/16x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"black bear","coyote","mule deer","brown bear","boar"}));
}
