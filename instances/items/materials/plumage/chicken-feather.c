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
        set("name", "Chicken Feather");
        set("short", "Chicken Feather");
        set("aliases", ({ "feather", "chicken feather" }));
        set("blueprint", "chicken feather");
    }
}
