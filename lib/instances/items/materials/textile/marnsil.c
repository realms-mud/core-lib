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
        set("name", "Marnsil");
        set("short", "Marnsil");
        set("aliases", ({ "cloth", "textile", "marnsil" }));
        set("blueprint", "marnsil");
    }
}
