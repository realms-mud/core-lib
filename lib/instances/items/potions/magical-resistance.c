//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Potion of Magic Resistance");
        set("short", "Potion of Magic Resistance");
        set("aliases", ({ "magic resistance", "potion", "magic resistance potion",
            "potion of magic resistance" }));
        set("blueprint", "magic resistance potion");
    }
}
