//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "east");
    addFeature("/lib/environment/features/landforms/hollow.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-1/0x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/0x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"ruffian","hunter","outlaw","mink"}));
}
