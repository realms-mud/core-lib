//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "east");
    addFeature("/lib/environment/features/landforms/hill.c", "east");
    addFeature("/lib/environment/features/water/gulley-creek.c", "east");

    addExit("east", "/areas/eledhel/west-rural-two/18x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/west-rural-two/16x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
