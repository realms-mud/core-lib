//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "northeast");
    addFeature("/lib/environment/features/trees/willow-stand.c", "northeast");

    addExit("east", "/areas/eledhel/west-rural-two/16x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/west-rural-two/14x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
