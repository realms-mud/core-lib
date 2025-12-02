//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/butte.c", "west");
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");

    addExit("south", "/areas/tol-dhurath/temple-exterior/22x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/temple-exterior/21x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/temple-exterior/23x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"white-tail deer","ruffian"}));
}
