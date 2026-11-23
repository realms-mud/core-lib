//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/knoll.c", "south");
    addFeature("/lib/environment/features/trees/hazel-stand.c", "east");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "southwest");
    addItem("/lib/environment/items/objects/boundary-stone.c", "north");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/eolach/approach/8x2.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/6x2.c");
}
