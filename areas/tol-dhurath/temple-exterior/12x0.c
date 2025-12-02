//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "south");

    addExit("north", "/areas/tol-dhurath/temple-exterior/12x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"hunter","ruffian","coyote","outlaw","boar","kit fox"}));
}
