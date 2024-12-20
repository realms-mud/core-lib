//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "east");
    addFeature("/lib/environment/features/trees/ash-stand.c", "west");
    addFeature("/lib/environment/features/trees/basswood-stand.c", "north");

    addExit("east", "/areas/tol-dhurath/forest-2/23x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"white-tail deer","red squirrel","outlaw"}));
}
