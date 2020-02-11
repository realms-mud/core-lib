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
        set("name", "Ebony Seed Pod");
        set("short", "Ebony Seed Pod");
        set("aliases", ({ "ebony seed pod", "seed pod", "pod", "seed",
            "ebony seed" }));
        set("blueprint", "ebony seed pod");
    }
}
