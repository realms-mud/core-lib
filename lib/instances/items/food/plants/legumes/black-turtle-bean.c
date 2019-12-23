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
        set("name", "black Turtle Bean");
        set("short", "black Turtle Bean");
        set("aliases", ({ "bean", "black turtle bean", "turtle bean" }));
        set("blueprint", "black turtle bean");
    }
}
