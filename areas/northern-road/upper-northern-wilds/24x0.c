//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/promontory.c", "north");
    addFeature("/lib/environment/features/water/spring.c", "south");
    addItem("/lib/environment/items/objects/boundary-stone.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addDecorator("village road T-north");
    addExit("west", "/areas/northern-road/upper-northern-wilds/23x0.c");
    addExit("east", "/areas/northern-road/minlach-approaches/0x4.c");
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/approach.c");
}
