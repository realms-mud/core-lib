//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "northeast");

    addExit("west", "/areas/tol-dhurath/forest-4/21x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-4/22x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
