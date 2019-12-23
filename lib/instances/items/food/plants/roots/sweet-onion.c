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
        set("name", "Sweet Onion");
        set("short", "Sweet Onion");
        set("aliases", ({ "sweet onion", "onion" }));
        set("blueprint", "sweet onion");
    }
}
