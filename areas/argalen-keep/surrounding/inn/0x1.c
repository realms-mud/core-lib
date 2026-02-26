//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/inn.c");
    addItem("/lib/environment/items/lighting/hearth.c", "west");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/furniture/small-shelf.c", "east");
    addItem("/lib/environment/items/lighting/window.c", "north");

    addExit("south", "/areas/argalen-keep/surrounding/inn/0x0.c");
}
