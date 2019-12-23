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
        set("name", "Russet Potato");
        set("short", "Russet Potato");
        set("aliases", ({ "russet potato", "potato" }));
        set("blueprint", "russet potato");
    }
}
