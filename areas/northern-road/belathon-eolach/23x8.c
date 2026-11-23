//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/water/field-drain.c", "south");
    addItem("/lib/environment/items/objects/signPost.c", "northwest");
    addItem("/lib/environment/items/marine/crate-of-fish.c", "northeast");
    addItem("/lib/environment/items/marine/fishing-net.c", "southeast");
    addItem("/lib/environment/items/objects/packing-crate.c", "southwest");

    addDecorator("village road T-north");

    addExit("north", "/areas/eledhel/estates/belathon/approach/0x0.c");
    addExit("east", "/areas/northern-road/belathon-eolach/24x8.c");
    addExit("west", "/areas/northern-road/belathon-eolach/22x8.c");
}
