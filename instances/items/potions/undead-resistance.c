//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Potion of Undead Resistance");
        set("short", "Potion of Undead Resistance");
        set("aliases", ({ "undead resistance", "potion", "undead resistance potion",
            "potion of undead resistance" }));
        set("blueprint", "undead resistance");
    }
}
