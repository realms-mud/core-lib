//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Paralysis Resistance");
    set("short", "Potion of Paralysis Resistance");
    set("aliases", ({ "paralysis resistance", "potion", "paralysis resistance potion",
        "potion of paralysis resistance" }));
    set("blueprint", "paralysis resistance potion");
}
