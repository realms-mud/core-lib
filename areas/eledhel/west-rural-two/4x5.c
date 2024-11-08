//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "west");
    addFeature("/lib/environment/features/trees/willow-stand.c", "west");
    addFeature("/lib/environment/features/landforms/ridge.c", "west");

    addExit("west", "/areas/eledhel/west-rural-two/3x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/4x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
