//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "south");
    addFeature("/lib/environment/features/landforms/promontory.c", "south");

    addExit("west", "/areas/eledhel/west-rural-two/13x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/eledhel/west-rural-two/15x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
