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
        set("name", "Spruce Cone");
        set("short", "Spruce Cone");
        set("aliases", ({ "spruce cone", "cone" }));
        set("blueprint", "spruce cone");
    }
}
