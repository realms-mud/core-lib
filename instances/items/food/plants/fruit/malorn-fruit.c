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
        set("name", "Malorn Fruit");
        set("short", "Malorn Fruit");
        set("aliases", ({ "malorn fruit", "malorn" }));
        set("blueprint", "malorn fruit");
    }
}
