//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Koa Seed Pod");
    set("short", "Koa Seed Pod");
    set("aliases", ({ "koa seed pod", "seed pod", "pod", "seed",
        "koa seed" }));
    set("blueprint", "koa seed pod");
}
