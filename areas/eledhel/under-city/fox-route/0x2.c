//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addItem("/lib/environment/items/objects/soot-smudged-wall.c", "north");
    addExit("south", "/areas/eledhel/under-city/fox-route/0x3.c");
    addExit("north", "/areas/eledhel/under-city/fox-route/0x1.c");
}
