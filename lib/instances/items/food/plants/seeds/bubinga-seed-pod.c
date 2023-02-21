//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bubinga Seed Pod");
    set("short", "Bubinga Seed Pod");
    set("aliases", ({ "bubinga seed pod", "seed pod", "pod", "seed",
        "bubinga seed" }));
    set("blueprint", "bubinga seed pod");
}
