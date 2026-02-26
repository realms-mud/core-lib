//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-temple.c");
    addItem("/lib/environment/items/lighting/stained-glass-window.c", "west");
    addItem("/lib/environment/items/lighting/stained-glass-window.c", "east");
    addItem("/lib/environment/items/furniture/pew.c", "south");
    addItem("/lib/environment/items/furniture/pew.c", "north");
    addItem("/lib/environment/items/furniture/altar-table.c", "north");
    addItem("/lib/environment/items/lighting/candelabra.c", "north");

    addObject("/areas/argalen-keep/surrounding/characters/osric/osric.c");

    addExitWithDoor("east", "/areas/argalen-keep/surrounding/12x6.c");
}
