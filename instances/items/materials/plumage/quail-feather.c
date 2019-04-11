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
        set("name", "Quail Feather");
        set("short", "Quail Feather");
        set("aliases", ({ "feather", "quail feather" }));
        set("blueprint", "quail feather");
    }
}
