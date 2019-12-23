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
        set("name", "Poplar Catkin");
        set("short", "Poplar Catkin");
        set("aliases", ({ "poplar catkins", "poplar catkin", "catkins", "catkin" }));
        set("blueprint", "poplar catkin");
    }
}
