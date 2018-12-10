//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Purple Tomato");
        set("short", "Purple Tomato");
        set("aliases", ({ "purple tomato", "tomato" }));
        set("blueprint", "purple tomato");
    }
}
