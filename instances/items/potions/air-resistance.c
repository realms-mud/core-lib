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
        set("name", "Potion of Air Resistance");
        set("short", "Potion of Air Resistance");
        set("aliases", ({ "air resistance", "potion", "air resistance potion",
            "potion of air resistance" }));
        set("blueprint", "air resistance");
    }
}
