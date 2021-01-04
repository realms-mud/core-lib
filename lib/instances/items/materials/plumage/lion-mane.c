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
        set("name", "Lion Mane");
        set("short", "Lion Mane");
        set("aliases", ({ "hair", "lion mane", "mane" }));
        set("blueprint", "lion mane");
    }
}
