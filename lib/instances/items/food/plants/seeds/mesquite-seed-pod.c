//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Mesquite Seed Pod");
    set("short", "Mesquite Seed Pod");
    set("aliases", ({ "mesquite seed pod", "seed pod", "pod", "seed",
        "mesquite seed" }));
    set("blueprint", "mesquite seed pod");
}
