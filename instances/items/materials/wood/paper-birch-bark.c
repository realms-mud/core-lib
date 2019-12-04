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
        set("name", "Paper Birch Bark");
        set("short", "Paper Birch Bark");
        set("aliases", ({ "paper birch bark", "birch bark", "bark" }));
        set("blueprint", "paper birch bark");
    }
}
