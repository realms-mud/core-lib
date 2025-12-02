//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Speed");
    set("short", "Potion of Speed");
    set("aliases", ({ "speed", "potion", "speed potion",
        "potion of speed" }));
    set("blueprint", "speed potion");
}
