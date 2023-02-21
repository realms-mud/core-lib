//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "west");

    addExit("west", "/areas/tol-dhurath/forest-4/23x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"warg","keeper of the night","beaver"}));
}
