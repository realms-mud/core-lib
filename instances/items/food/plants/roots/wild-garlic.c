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
        set("name", "Wild Garlic");
        set("short", "Wild Garlic");
        set("aliases", ({ "wild garlic", "garlic" }));
        set("blueprint", "wild garlic");
    }
}
