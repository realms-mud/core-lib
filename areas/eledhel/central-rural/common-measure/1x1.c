//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/kitchen.c");
    addItem("/lib/environment/items/lighting/fireplace.c", "north");
    addItem("/lib/environment/items/furniture/workbench.c", "east");
    addItem("/lib/environment/items/crafts/flour-sack.c", "south");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "west");

    addExit("west", "/areas/eledhel/central-rural/common-measure/0x1.c");
    addExit("north", "/areas/eledhel/central-rural/common-measure/1x0.c");
}
