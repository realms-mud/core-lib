//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Thrush Feather");
        set("short", "Thrush Feather");
        set("aliases", ({ "feather", "thrush feather" }));
        set("blueprint", "thrush feather");
    }
}
