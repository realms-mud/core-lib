//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/black-cherry-stand.c", "northeast");
    addFeature("/lib/environment/features/water/creek.c", "east");
    addFeature("/lib/environment/features/trees/dogwood-stand.c", "north");

    addExit("west", "/areas/tol-dhurath/entry/19x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","coyote"}));
}
