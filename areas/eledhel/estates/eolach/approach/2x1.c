//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");
    addFeature("/lib/environment/features/trees/hazel-stand.c", "south");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "northeast");
    addFeature("/lib/environment/features/landforms/knoll.c", "southwest");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/eolach/approach/3x1.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/1x1.c");
}
