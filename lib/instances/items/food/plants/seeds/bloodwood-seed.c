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
        set("name", "Bloodwood Seed");
        set("short", "Bloodwood Seed");
        set("aliases", ({ "bloodwood seed", "seed" }));
        set("blueprint", "bloodwood seed");
    }
}
