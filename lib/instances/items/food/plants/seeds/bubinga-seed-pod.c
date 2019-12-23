//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Bubinga Seed Pod");
        set("short", "Bubinga Seed Pod");
        set("aliases", ({ "bubinga seed pod", "seed pod", "seed",
            "bubinga seed" }));
        set("blueprint", "bubinga seed pod");
    }
}
