//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Undead Resistance");
    set("short", "Potion of Undead Resistance");
    set("aliases", ({ "undead resistance", "potion", "undead resistance potion",
        "potion of undead resistance" }));
    set("blueprint", "undead resistance potion");
}
