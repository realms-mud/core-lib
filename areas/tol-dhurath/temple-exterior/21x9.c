//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "west");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "southwest");

    addExit("south", "/areas/tol-dhurath/temple-exterior/21x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","boar","outlaw","gray wolf"}));
}
