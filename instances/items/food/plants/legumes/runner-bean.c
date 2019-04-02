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
        set("name", "Runner Bean");
        set("short", "Runner Bean");
        set("aliases", ({ "bean", "runner bean" }));
        set("blueprint", "runner bean");
    }
}
