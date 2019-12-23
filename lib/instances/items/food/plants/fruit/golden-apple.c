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
        set("name", "Golden Apple");
        set("short", "Golden Apple");
        set("aliases", ({ "golden apple", "apple" }));
        set("blueprint", "golden apple");
    }
}
