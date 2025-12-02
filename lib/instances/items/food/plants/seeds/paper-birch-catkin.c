//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Paper Birch Catkin");
    set("short", "Paper Birch Catkin");
    set("aliases", ({ "paper birch catkins", "paper birch catkin", "catkins", "catkin",
        "birch catkins", "birch catkin", }));
    set("blueprint", "paper birch catkin");
}
