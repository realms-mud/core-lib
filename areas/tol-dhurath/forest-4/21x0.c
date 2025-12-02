//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-4/20x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-4/22x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"weasel","keeper of the night","warg","white-tail deer"}));
}
