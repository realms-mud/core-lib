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
        set("name", "Terra cotta");
        set("short", "Terra cotta");
        set("aliases", ({ "clay", "terra cotta" }));
        set("blueprint", "terra cotta");
    }
}
