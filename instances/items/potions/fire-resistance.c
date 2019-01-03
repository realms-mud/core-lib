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
        set("name", "Potion of Fire Resistance");
        set("short", "Potion of Fire Resistance");
        set("aliases", ({ "fire resistance", "potion", "fire resistance potion",
            "potion of fire resistance" }));
        set("blueprint", "fire resistance");
    }
}
