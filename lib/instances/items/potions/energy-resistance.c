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
        set("name", "Potion of Energy Resistance");
        set("short", "Potion of Energy Resistance");
        set("aliases", ({ "energy resistance", "potion", "energy resistance potion",
            "potion of energy resistance" }));
        set("blueprint", "energy resistance potion");
    }
}
