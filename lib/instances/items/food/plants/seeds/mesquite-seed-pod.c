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
        set("name", "Mesquite Seed Pod");
        set("short", "Mesquite Seed Pod");
        set("aliases", ({ "mesquite seed pod", "seed pod", "pod", "seed",
            "mesquite seed" }));
        set("blueprint", "mesquite seed pod");
    }
}
