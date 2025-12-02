//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Aspen Catkin");
    set("short", "Aspen Catkin");
    set("aliases", ({ "aspen catkins", "aspen catkin", "catkins", "catkin" }));
    set("blueprint", "aspen catkin");
}
