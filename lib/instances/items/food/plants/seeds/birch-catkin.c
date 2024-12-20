//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Birch Catkin");
    set("short", "Birch Catkin");
    set("aliases", ({ "birch catkins", "birch catkin", "catkins", "catkin" }));
    set("blueprint", "birch catkin");
}
