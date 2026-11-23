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
    addFeature("/lib/environment/features/trees/yew-stand.c", "north");
    addFeature("/lib/environment/features/vegetation/ash-coppice.c",
        "south");
    addItem("/lib/environment/items/crafts/lumber-stack.c", "southwest");
    addItem("/lib/environment/items/objects/hand-cart.c", "southeast");

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/eolach/approach/5x1.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/3x1.c");
}
