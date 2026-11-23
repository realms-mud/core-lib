//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addItem("/lib/environment/items/objects/signPost.c", "east");

    addDecorator("village road corner SW");

    addExit("south", "/areas/eledhel/estates/belectar/approach/8x1.c");
    addExit("west", "/areas/eledhel/estates/belectar/approach/7x0.c");
}
