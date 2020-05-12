//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "northeast");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "northeast");
    addFeature("/lib/environment/features/trees/rosewood-stand.c", "northeast");

    addExit("east", "/areas/tol-dhurath/forest-2/1x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-3/0x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","outlaw","white-tail deer","timber wolf","kit fox"}));
}
