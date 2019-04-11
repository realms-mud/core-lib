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
        set("name", "Pegasus Feather");
        set("short", "Pegasus Feather");
        set("aliases", ({ "feather", "pegasus feather" }));
        set("blueprint", "pegasus feather");
    }
}
