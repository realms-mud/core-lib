//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/maple-stand.c", "northwest");
    addFeature("/lib/environment/features/landforms/ridge.c", "northwest");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "northwest");

    addExit("south", "/areas/eledhel/west-rural-two/13x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/eledhel/west-rural-two/14x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
