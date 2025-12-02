//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Dexterity");
    set("short", "Potion of Dexterity");
    set("aliases", ({ "dexterity", "potion", "dexterity potion",
        "potion of dexterity" }));
    set("blueprint", "dexterity potion");
}
