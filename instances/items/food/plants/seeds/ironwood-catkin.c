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
        set("name", "Ironwood Catkin");
        set("short", "Ironwood Catkin");
        set("aliases", ({ "ironwood catkins", "ironwood catkin", "catkins", "catkin" }));
        set("blueprint", "ironwood catkin");
    }
}
