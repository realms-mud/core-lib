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
        set("name", "Koa Seed Pod");
        set("short", "Koa Seed Pod");
        set("aliases", ({ "koa seed pod", "seed pod", "pod", "seed",
            "koa seed" }));
        set("blueprint", "koa seed pod");
    }
}
