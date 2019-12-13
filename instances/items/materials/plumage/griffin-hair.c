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
        set("name", "Griffin Hair");
        set("short", "Griffin Hair");
        set("aliases", ({ "hair", "griffin hair" }));
        set("blueprint", "griffin hair");
    }
}
