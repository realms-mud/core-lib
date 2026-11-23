//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/barley-field.c",
        "north");
    addItem("/lib/environment/items/objects/sack-pile.c", "south");
    addItem("/lib/environment/items/objects/hand-cart.c", "southwest");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/eolach/approach/6x0.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/4x0.c");
}
