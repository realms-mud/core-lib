//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Sweet Potato");
        set("short", "Sweet Potato");
        set("aliases", ({ "sweet potato", "potato" }));
        set("blueprint", "sweet potato");
    }
}
