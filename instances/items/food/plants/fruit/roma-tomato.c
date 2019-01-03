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
        set("name", "Roma Tomato");
        set("short", "Roma Tomato");
        set("aliases", ({ "roma tomato", "tomato" }));
        set("blueprint", "roma tomato");
    }
}
