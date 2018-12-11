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
        set("name", "Hardneck Garlic");
        set("short", "Hardneck Garlic");
        set("aliases", ({ "hardneck garlic", "garlic" }));
        set("blueprint", "hardneck garlic");
    }
}
