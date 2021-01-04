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
        set("name", "Green Tomato");
        set("short", "Green Tomato");
        set("aliases", ({ "green tomato", "tomato" }));
        set("blueprint", "green tomato");
    }
}
