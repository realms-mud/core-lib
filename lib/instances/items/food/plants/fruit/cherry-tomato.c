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
        set("name", "Cherry Tomato");
        set("short", "Cherry Tomato");
        set("aliases", ({ "cherry tomato", "tomato" }));
        set("blueprint", "cherry tomato");
    }
}
