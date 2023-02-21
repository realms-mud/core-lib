//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Purple Heart Seed Pod");
    set("short", "Purple Heart Seed Pod");
    set("aliases", ({ "purple heart seed pod", "seed pod", 
        "purple heart seed", "seed" }));
    set("blueprint", "purple heart seed pod");
}
