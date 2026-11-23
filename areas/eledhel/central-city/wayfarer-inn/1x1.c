//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/bedroom.c");
    setShortDescription("A plain guest room above the Wayfarer Inn");
    addItem("/lib/environment/items/furniture/canopy-bed.c", "north");
    addItem("/lib/environment/items/furniture/chair.c", "west");
    addExit("west", "/areas/eledhel/central-city/wayfarer-inn/0x1.c");
}
