//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Potion of Poison Resistance");
        set("short", "Potion of Poison Resistance");
        set("aliases", ({ "poison resistance", "potion", "poison resistance potion",
            "potion of poison resistance" }));
        set("blueprint", "poison resistance potion");
    }
}
