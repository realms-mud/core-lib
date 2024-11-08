//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gulley-creek.c", "east");

    addExit("south", "/areas/tol-dhurath/forest-1/6x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","gray fox","mink","white-tail deer"}));
}
