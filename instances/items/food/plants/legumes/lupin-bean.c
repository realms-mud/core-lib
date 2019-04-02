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
        set("name", "Lupin Bean");
        set("short", "Lupin Bean");
        set("aliases", ({ "bean", "lupin bean" }));
        set("blueprint", "lupin bean");
    }
}
