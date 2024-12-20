//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/kingwood-stand.c", "northwest");

    addExit("west", "/areas/tol-dhurath/forest-4/2x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"gray fox","ruffian","panther","mule deer","outlaw","groundhog","mink"}));
}
