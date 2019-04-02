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
        set("name", "Snow Pea");
        set("short", "Snow Pea");
        set("aliases", ({ "pea", "snow pea" }));
        set("blueprint", "snow pea");
    }
}
