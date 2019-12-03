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
        set("name", "Cottonwood Catkins");
        set("short", "Cottonwood Catkins");
        set("aliases", ({ "cottonwood catkins", "cottonwood catkin", "catkins", "catkin" }));
        set("blueprint", "cottonwood catkins");
    }
}
