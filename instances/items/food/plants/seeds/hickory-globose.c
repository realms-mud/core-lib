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
        set("name", "Hickory Globose");
        set("short", "Hickory Globose");
        set("aliases", ({ "hickory globose", "globose" }));
        set("blueprint", "hickory globose");
    }
}
