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
        set("name", "Potion of Earth Resistance");
        set("short", "Potion of Earth Resistance");
        set("aliases", ({ "earth resistance", "potion", "earth resistance potion",
            "potion of earth resistance" }));
        set("blueprint", "earth resistance potion");
    }
}
