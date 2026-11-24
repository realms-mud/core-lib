//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addItem("/lib/environment/items/lighting/fireplace.c", "north");
    addItem("/lib/environment/items/furniture/herb-drying-rack.c", "east");
    addShop("/lib/environment/shopInventories/herbalist.c");
    addObject("/areas/tol-dhurath/northern-trail/characters/ithra.c");

    addExit("south", "/areas/tol-dhurath/northern-trail/6x4.c");
}
