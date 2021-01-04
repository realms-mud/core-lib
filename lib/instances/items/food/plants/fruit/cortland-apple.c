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
        set("name", "Cortland Apple");
        set("short", "Cortland Apple");
        set("aliases", ({ "cortland apple", "apple" }));
        set("blueprint", "cortland apple");
    }
}
