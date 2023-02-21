//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Marblewood Seed Pod");
    set("short", "Marblewood Seed Pod");
    set("aliases", ({ "marblewood seed pod", "seed pod", "pod", "seed",
        "marblewood seed" }));
    set("blueprint", "marblewood seed pod");
}
