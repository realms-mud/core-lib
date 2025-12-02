//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "east");
    addFeature("/lib/environment/features/trees/ash-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/hollow.c", "south");

    addExit("east", "/areas/tol-dhurath/entry/24x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"gray fox","ruffian","white-tail deer"}));
}
