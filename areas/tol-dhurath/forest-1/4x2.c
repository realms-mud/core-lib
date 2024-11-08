//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "southwest");

    addExit("south", "/areas/tol-dhurath/forest-1/4x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"otter","ruffian","white-tail deer"}));
}
