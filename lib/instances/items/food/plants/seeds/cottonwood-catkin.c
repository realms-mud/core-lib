//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Cottonwood Catkin");
        set("short", "Cottonwood Catkin");
        set("aliases", ({ "cottonwood catkins", "cottonwood catkin", "catkins", "catkin" }));
        set("blueprint", "cottonwood catkin");
    }
}
