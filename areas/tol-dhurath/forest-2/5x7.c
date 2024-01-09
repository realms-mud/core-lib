//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/walnut-stand.c", "west");
    addFeature("/lib/environment/features/trees/maple-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/combe.c", "east");

    addExit("north", "/areas/tol-dhurath/forest-2/5x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"coyote","white-tail deer","hunter"}));
}
