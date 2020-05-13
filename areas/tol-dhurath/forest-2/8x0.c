//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "south");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "northwest");

    addExit("north", "/areas/tol-dhurath/forest-2/8x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"ruffian","white-tail deer"}));
}
