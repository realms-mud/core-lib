//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Magic Resistance");
    set("short", "Potion of Magic Resistance");
    set("aliases", ({ "magic resistance", "potion", "magic resistance potion",
        "potion of magic resistance" }));
    set("blueprint", "magic resistance potion");
}
