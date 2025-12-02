//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "east");
    addFeature("/lib/environment/features/trees/aspen-stand.c", "east");
    addFeature("/lib/environment/features/landforms/ridge.c", "east");

    addExit("north", "/areas/eledhel/west-rural-two/21x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/eledhel/west-rural-two/21x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
