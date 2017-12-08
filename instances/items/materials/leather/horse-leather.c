//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Horse leather");
        set("short", "Horse leather");
        set("aliases", ({ "leather" }));
        set("blueprint", "horse leather");
    }
}
