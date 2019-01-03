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
        set("name", "Rhudnalt");
        set("short", "Rhudnalt");
        set("aliases", ({ "metal", "rhudnalt" }));
        set("blueprint", "rhudnalt");
    }
}
