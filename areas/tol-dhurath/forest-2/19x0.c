//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-2/18x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"raccoon","kit fox","outlaw"}));
}
