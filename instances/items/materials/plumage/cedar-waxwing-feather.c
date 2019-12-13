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
        set("name", "Cedar Waxwing Feather");
        set("short", "Cedar Waxwing Feather");
        set("aliases", ({ "feather", "cedar waxwing feather", "waxwing feather" }));
        set("blueprint", "cedar waxwing feather");
    }
}
