//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "west");

    addExit("south", "/areas/tol-dhurath/forest-3/16x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-3/16x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"ruffian","white-tail deer","outlaw"}));
}
