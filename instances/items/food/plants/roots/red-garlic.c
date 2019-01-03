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
        set("name", "Red Garlic");
        set("short", "Red Garlic");
        set("aliases", ({ "red garlic", "garlic" }));
        set("blueprint", "red garlic");
    }
}
