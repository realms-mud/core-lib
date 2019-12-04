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
        set("name", "Ambrosia Apple");
        set("short", "Ambrosia Apple");
        set("aliases", ({ "ambrosia apple", "apple" }));
        set("blueprint", "ambrosia apple");
    }
}
