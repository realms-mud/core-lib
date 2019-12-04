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
        set("name", "Lacewood Seed Pod");
        set("short", "Lacewood Seed Pod");
        set("aliases", ({ "lacewood seed pod", "seed pod", "seed",
            "lacewood seed" }));
        set("blueprint", "lacewood seed pod");
    }
}
