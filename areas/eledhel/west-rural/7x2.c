//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/tor.c", "west");
    addFeature("/lib/environment/features/water/ravine-brook.c", "west");
    addFeature("/lib/environment/features/trees/maple-stand.c", "west");

    addExit("west", "/areas/eledhel/west-rural/6x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/eledhel/west-rural/8x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
