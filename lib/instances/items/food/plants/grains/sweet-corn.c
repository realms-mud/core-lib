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
        set("name", "Sweet Corn");
        set("short", "Sweet Corn");
        set("aliases", ({ "sweet corn", "corn" }));
        set("blueprint", "sweet corn");
    }
}
