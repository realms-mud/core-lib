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
        set("name", "Paper Birch Catkin");
        set("short", "Paper Birch Catkin");
        set("aliases", ({ "paper birch catkins", "paper birch catkin", "catkins", "catkin",
            "birch catkins", "birch catkin", }));
        set("blueprint", "paper birch catkin");
    }
}
