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
        set("name", "Cormorant Feather");
        set("short", "Cormorant Feather");
        set("aliases", ({ "feather", "cormorant feather" }));
        set("blueprint", "cormorant feather");
    }
}
