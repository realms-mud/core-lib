//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addItem("/areas/eledhel/estates/eolach/items/forester-notice-board.c",
        "north");
    addFeature("/lib/environment/features/trees/ash-stand.c", "west");
    addFeature("/lib/environment/features/water/field-drain.c", "southwest");
    addItem("/lib/environment/items/objects/boundary-stone.c", "northwest");

    addDecorator("village road corner SE");

    addExit("east", "/areas/eledhel/estates/eolach/approach/1x1.c");
    addExit("south", "/areas/eledhel/estates/eolach/approach/0x2.c");
}
