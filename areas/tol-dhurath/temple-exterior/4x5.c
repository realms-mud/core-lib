//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");

    addExit("south", "/areas/tol-dhurath/temple-exterior/4x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"white-tail deer","ruffian","outlaw"}));
}
