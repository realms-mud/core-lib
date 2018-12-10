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
        set("name", "Purple Potato");
        set("short", "Purple Potato");
        set("aliases", ({ "purple potato", "potato" }));
        set("blueprint", "purple potato");
    }
}
