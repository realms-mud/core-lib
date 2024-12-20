//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Lacewood Seed Pod");
    set("short", "Lacewood Seed Pod");
    set("aliases", ({ "lacewood seed pod", "seed pod", "pod", "seed",
        "lacewood seed" }));
    set("blueprint", "lacewood seed pod");
}
