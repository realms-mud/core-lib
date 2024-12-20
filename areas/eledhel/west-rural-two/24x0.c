//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "north");
    addFeature("/lib/environment/features/trees/McIntosh-apple-stand.c", "north");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "north");

    addExit("north", "/areas/eledhel/west-rural-two/24x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/west-rural-two/23x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
