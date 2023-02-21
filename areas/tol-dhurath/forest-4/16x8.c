//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gulley-creek.c", "south");
    addFeature("/lib/environment/features/trees/ash-stand.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-4/15x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-4/16x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"weasel","coyote","outlaw","badger","red wolf"}));
}
