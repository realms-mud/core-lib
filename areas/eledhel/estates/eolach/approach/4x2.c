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
    addFeature("/lib/environment/features/plants/rye-field.c", "north");
    addFeature("/lib/environment/features/agriculture/threshing-floor.c",
        "northeast");
    addItem("/lib/environment/items/objects/sack-pile.c", "south");
    addItem("/lib/environment/items/objects/hand-cart.c", "southwest");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/eolach/approach/5x2.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/3x2.c");
}
