//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "southwest");
    addFeature("/lib/environment/features/trees/grape-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/hollow.c", "southwest");

    addExit("west", "/areas/eledhel/west-rural/17x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural/18x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
