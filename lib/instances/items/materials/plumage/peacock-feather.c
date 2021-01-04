//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Peacock Feather");
        set("short", "Peacock Feather");
        set("aliases", ({ "feather", "peacock feather" }));
        set("blueprint", "peacock feather");
    }
}
