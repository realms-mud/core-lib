//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("A cottage stands above Dhorlen's mill lane");
    addDecorator("village cottage");
    addItem("/lib/environment/items/objects/woodpile.c", "north");
    addExit("west", "/areas/eledhel/dhorlen/4x2.c");
}
