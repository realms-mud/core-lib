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
        set("name", "Aspen Catkin");
        set("short", "Aspen Catkin");
        set("aliases", ({ "aspen catkins", "aspen catkin", "catkins", "catkin" }));
        set("blueprint", "aspen catkin");
    }
}
