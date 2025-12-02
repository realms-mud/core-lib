//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Acid Resistance");
    set("short", "Potion of Acid Resistance");
    set("aliases", ({ "acid resistance", "potion", "acid resistance potion",
        "potion of acid resistance" }));
    set("blueprint", "acid resistance potion");
}
