//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "southeast");
    addFeature("/lib/environment/features/trees/honeycrisp-apple-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/hillock.c", "southeast");

    addExit("south", "/lib/tests/support/pathfinding/24x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/lib/tests/support/pathfinding/23x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

