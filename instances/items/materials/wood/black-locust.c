//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Black Locust");
        set("short", "Black Locust");
        set("aliases", ({ "wood", "black locust", "locust" }));
        set("blueprint", "black locust");
    }
}
