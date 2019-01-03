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
        set("name", "Burgundy Garlic");
        set("short", "Burgundy Garlic");
        set("aliases", ({ "burgundy garlic", "garlic" }));
        set("blueprint", "burgundy garlic");
    }
}
