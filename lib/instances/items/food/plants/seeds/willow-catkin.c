//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Willow Catkin");
    set("short", "Willow Catkin");
    set("aliases", ({ "willow catkins", "willow catkin", "catkins", "catkin" }));
    set("blueprint", "willow catkin");
}
