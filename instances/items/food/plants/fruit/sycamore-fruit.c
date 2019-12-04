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
        set("name", "Sycamore Fruit");
        set("short", "Sycamore Fruit");
        set("aliases", ({ "sycamore fruit", "sycamore" }));
        set("blueprint", "sycamore fruit");
    }
}
