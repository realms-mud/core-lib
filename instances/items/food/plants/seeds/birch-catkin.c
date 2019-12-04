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
        set("name", "Birch Catkin");
        set("short", "Birch Catkin");
        set("aliases", ({ "birch catkins", "birch catkin", "catkins", "catkin" }));
        set("blueprint", "birch catkin");
    }
}
