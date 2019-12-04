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
        set("name", "Dogwood Fruit");
        set("short", "Dogwood Fruit");
        set("aliases", ({ "dogwood fruit", "dogwood" }));
        set("blueprint", "dogwood fruit");
    }
}
