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
        set("name", "Mahogany Flower");
        set("short", "Mahogany Flower");
        set("aliases", ({ "mahogany flower", "mahogany" }));
        set("blueprint", "mahogany flower");
    }
}
