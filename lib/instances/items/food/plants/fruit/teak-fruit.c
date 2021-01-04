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
        set("name", "Teak Fruit");
        set("short", "Teak Fruit");
        set("aliases", ({ "teak fruit", "teak" }));
        set("blueprint", "teak fruit");
    }
}
