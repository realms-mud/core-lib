//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Montmorency Cherry");
        set("short", "Montmorency Cherry");
        set("aliases", ({ "cherry", "montmorency cherry" }));
        set("blueprint", "montmorency cherry");
    }
}
