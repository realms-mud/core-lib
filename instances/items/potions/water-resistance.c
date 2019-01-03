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
        set("name", "Potion of Water Resistance");
        set("short", "Potion of Water Resistance");
        set("aliases", ({ "water resistance", "potion", "water resistance potion",
            "potion of water resistance" }));
        set("blueprint", "water resistance");
    }
}
