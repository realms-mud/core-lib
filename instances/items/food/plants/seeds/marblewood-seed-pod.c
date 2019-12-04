//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Marblewood Seed Pod");
        set("short", "Marblewood Seed Pod");
        set("aliases", ({ "marblewood seed pod", "seed pod", "seed",
            "marblewood seed" }));
        set("blueprint", "marblewood seed pod");
    }
}
