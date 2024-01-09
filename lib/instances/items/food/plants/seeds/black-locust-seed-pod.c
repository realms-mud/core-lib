//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Black Locust Seed Pod");
    set("short", "Black Locust Seed Pod");
    set("aliases", ({ "black locust seed pod", "locust seed pod", "seed pod", 
        "seed", "black locust seed" }));
    set("blueprint", "black locust seed pod");
}
