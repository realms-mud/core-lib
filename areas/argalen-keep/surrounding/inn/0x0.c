//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/inn.c");
    addItem("/lib/environment/items/lighting/fireplace.c", "north");
    addItem("/lib/environment/items/lighting/candelabra.c", "south");
    addItem("/lib/environment/items/furniture/long-table.c", "west");
    addItem("/lib/environment/items/furniture/bench.c", "east");
    addItem("/lib/environment/items/lighting/window.c", "east");

    addObject("/areas/argalen-keep/surrounding/characters/aldric/aldric.c");

    addExitWithDoor("east", "/areas/argalen-keep/surrounding/11x5.c");
    addExit("north", "/areas/argalen-keep/surrounding/inn/0x1.c");
}
