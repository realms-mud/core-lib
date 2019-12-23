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
        set("name", "Black-Eyed Pea");
        set("short", "Black-Eyed Pea");
        set("aliases", ({ "pea", "black-eyed pea", "black eyed pea" }));
        set("blueprint", "black-eyed pea");
    }
}
