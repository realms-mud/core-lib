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
        set("name", "Kidney Bean");
        set("short", "Kidney Bean");
        set("aliases", ({ "bean", "kidney bean" }));
        set("blueprint", "kidney bean");
    }
}
