//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addItem("/lib/environment/items/crafts/grain-bin.c", "north");
    addObject("/areas/eledhel/estates/belectar/characters/steward.c");

    addDecorator("village road intersection");

    addExit("north", "/areas/eledhel/estates/belectar/grounds/2x0.c");
    addExit("east",
        "/areas/eledhel/estates/belectar/keep-interior/0x0.c");
    addExit("south",
        "/areas/eledhel/estates/belectar/grounds/2x2.c");
    addExit("west", "/areas/eledhel/estates/belectar/grounds/1x1.c");
}
