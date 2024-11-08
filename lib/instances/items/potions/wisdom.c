//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Wisdom");
    set("short", "Potion of Wisdom");
    set("aliases", ({ "wisdom", "potion", "wisdom potion",
        "potion of wisdom" }));
    set("blueprint", "wisdom potion");
}
