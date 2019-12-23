//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Choke Cherry");
        set("short", "Choke Cherry");
        set("aliases", ({ "cherry", "choke cherry" }));
        set("blueprint", "choke cherry");
    }
}
