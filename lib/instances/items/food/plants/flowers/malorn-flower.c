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
        set("name", "Malorn Flower");
        set("short", "Malorn Flower");
        set("aliases", ({ "malorn flower", "malorn" }));
        set("blueprint", "malorn flower");
    }
}
