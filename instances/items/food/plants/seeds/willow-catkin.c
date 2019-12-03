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
        set("name", "Willow Catkins");
        set("short", "Willow Catkins");
        set("aliases", ({ "willow catkins", "willow catkin", "catkins", "catkin" }));
        set("blueprint", "willow catkins");
    }
}
