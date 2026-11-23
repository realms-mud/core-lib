//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/bedroom.c");
    setShortDescription("A guest room above the Golden Flask");
    addItem("/lib/environment/items/furniture/canopy-bed.c", "north");
    addItem("/lib/environment/items/furniture/chair.c", "west");
    addExit("west", "/areas/eledhel/central-city/golden-flask/0x1.c");
}
