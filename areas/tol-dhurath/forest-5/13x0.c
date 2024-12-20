//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/alder-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/tor.c", "southeast");
    addFeature("/lib/environment/features/trees/willow-stand.c", "southeast");

    addExit("north", "/areas/tol-dhurath/forest-5/13x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-5/14x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
