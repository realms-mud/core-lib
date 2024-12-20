//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "northeast");
    addFeature("/lib/environment/features/trees/pine-stand.c", "northeast");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "northeast");

    addExit("east", "/areas/eledhel/west-rural-two/13x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/west-rural-two/11x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
