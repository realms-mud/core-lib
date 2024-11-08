//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "east");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "west");

    addExit("west", "/areas/tol-dhurath/entry/4x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","white-tail deer"}));
}
