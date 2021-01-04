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
        set("name", "Cedar Cone");
        set("short", "Cedar Cone");
        set("aliases", ({ "cedar cone", "cone" }));
        set("blueprint", "cedar cone");
    }
}
