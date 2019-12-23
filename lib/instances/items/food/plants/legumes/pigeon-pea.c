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
        set("name", "Pigeon Pea");
        set("short", "Pigeon Pea");
        set("aliases", ({ "pea", "pigeon pea" }));
        set("blueprint", "pigeon pea");
    }
}
