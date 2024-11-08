//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "east");
    addFeature("/lib/environment/features/trees/ash-stand.c", "east");

    addExit("south", "/areas/eledhel/west-rural-two/4x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/eledhel/west-rural-two/5x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/west-rural-two/3x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
