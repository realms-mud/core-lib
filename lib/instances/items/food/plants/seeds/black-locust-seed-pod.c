//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Black Locust Seed Pod");
        set("short", "Black Locust Seed Pod");
        set("aliases", ({ "black locust seed pod", "locust seed pod", "seed pod", 
            "seed", "black locust seed" }));
        set("blueprint", "black locust seed pod");
    }
}
