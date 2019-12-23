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
        set("name", "Yellow Potato");
        set("short", "Yellow Potato");
        set("aliases", ({ "yellow potato", "potato" }));
        set("blueprint", "yellow potato");
    }
}
