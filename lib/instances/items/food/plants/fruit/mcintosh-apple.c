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
        set("name", "McIntosh Apple");
        set("short", "McIntosh Apple");
        set("aliases", ({ "mcintosh apple", "apple" }));
        set("blueprint", "mcintosh apple");
    }
}
