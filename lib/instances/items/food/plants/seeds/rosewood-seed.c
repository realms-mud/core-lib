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
        set("name", "Rosewood Seed");
        set("short", "Rosewood Seed");
        set("aliases", ({ "rosewood seed", "seed" }));
        set("blueprint", "rosewood seed");
    }
}
