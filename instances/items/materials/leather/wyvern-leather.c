//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Wyvern leather");
        set("short", "Wyvern leather");
        set("aliases", ({ "leather", "wyvern leather" }));
        set("blueprint", "wyvern leather");
    }
}
