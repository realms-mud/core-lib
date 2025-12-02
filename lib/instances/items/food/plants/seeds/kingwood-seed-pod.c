//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Kingwood Seed Pod");
    set("short", "Kingwood Seed Pod");
    set("aliases", ({ "kingwood seed pod", "seed pod", "pod", "seed",
        "kingwood seed" }));
    set("blueprint", "kingwood seed pod");
}
