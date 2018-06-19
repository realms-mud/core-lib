//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Potion of Wisdom");
        set("short", "Potion of Wisdom");
        set("aliases", ({ "wisdom", "potion", "wisdom potion",
            "potion of wisdom" }));
        set("blueprint", "wisdom");
    }
}
