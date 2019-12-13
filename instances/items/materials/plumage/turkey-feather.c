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
        set("name", "Turkey Feather");
        set("short", "Turkey Feather");
        set("aliases", ({ "feather", "turkey feather" }));
        set("blueprint", "turkey feather");
    }
}
