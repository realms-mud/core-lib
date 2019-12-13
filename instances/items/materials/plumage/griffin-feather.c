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
        set("name", "Griffin Feather");
        set("short", "Griffin Feather");
        set("aliases", ({ "feather", "griffin feather" }));
        set("blueprint", "griffin feather");
    }
}
