//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Potion of Electricity Resistance");
        set("short", "Potion of Electricity Resistance");
        set("aliases", ({ "electricity resistance", "potion", "electricity resistance potion",
            "potion of electricity resistance" }));
        set("blueprint", "electricity resistance");
    }
}
