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
        set("name", "Alder Catkins");
        set("short", "Alder Catkins");
        set("aliases", ({ "alder catkins", "alder catkin", "catkins", "catkin" }));
        set("blueprint", "alder catkins");
    }
}
