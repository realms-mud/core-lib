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
        set("name", "Magnolia Fruit");
        set("short", "Magnolia Fruit");
        set("aliases", ({ "magnolia fruit", "magnolia" }));
        set("blueprint", "magnolia fruit");
    }
}
