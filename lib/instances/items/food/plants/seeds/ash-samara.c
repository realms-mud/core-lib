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
        set("name", "Ash Samara");
        set("short", "Ash Samara");
        set("aliases", ({ "ash samaras", "ash samara", "samaras", "samara" }));
        set("blueprint", "ash samara");
    }
}
