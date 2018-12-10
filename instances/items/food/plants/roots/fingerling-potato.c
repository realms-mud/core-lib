//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Fingerling Potato");
        set("short", "Fingerling Potato");
        set("aliases", ({ "fingerling potato", "potato" }));
        set("blueprint", "fingerling potato");
    }
}
