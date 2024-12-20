//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "south");
    addFeature("/lib/environment/features/landforms/precipice.c", "east");

    addExit("south", "/areas/tol-dhurath/temple-exterior/0x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"panther","outlaw"}));
}
