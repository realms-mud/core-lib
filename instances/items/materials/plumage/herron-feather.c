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
        set("name", "Herron Feather");
        set("short", "Herron Feather");
        set("aliases", ({ "feather", "herron feather" }));
        set("blueprint", "herron feather");
    }
}
