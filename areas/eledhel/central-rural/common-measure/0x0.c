//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/bedroom.c");
    addItem("/lib/environment/items/furniture/bed.c", "north");
    addItem("/lib/environment/items/furniture/chest-bench.c", "south");
    addItem("/lib/environment/items/lighting/window.c", "east");

    addExit("south", "/areas/eledhel/central-rural/common-measure/0x1.c");
}
