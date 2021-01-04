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
        set("name", "Unicorn leather");
        set("short", "Unicorn leather");
        set("aliases", ({ "leather", "unicorn leather" }));
        set("blueprint", "unicorn leather");
    }
}
