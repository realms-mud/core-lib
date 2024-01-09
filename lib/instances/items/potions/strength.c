//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Strength");
    set("short", "Potion of Strength");
    set("aliases", ({ "strength", "potion", "strength potion",
        "potion of strength" }));
    set("blueprint", "strength potion");
}
