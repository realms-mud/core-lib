//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "southwest");

    addExit("west", "/areas/eledhel/west-rural-two/11x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/eledhel/west-rural-two/13x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
