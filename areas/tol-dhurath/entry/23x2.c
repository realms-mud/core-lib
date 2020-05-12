//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "southwest");
    addFeature("/lib/environment/features/trees/ash-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/hollow.c", "southwest");

    addExit("east", "/areas/tol-dhurath/entry/24x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"gray fox","ruffian","timber wolf","boar"}));
}
