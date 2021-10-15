//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "north");
    addFeature("/lib/environment/features/trees/bing-cherry-stand.c", "north");
    addFeature("/lib/environment/features/landforms/dell.c", "north");

    addExit("west", "/areas/eledhel/west-rural-two/18x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/19x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
