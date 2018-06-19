//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Potion of Disease Resistance");
        set("short", "Potion of Disease Resistance");
        set("aliases", ({ "disease resistance", "potion", "disease resistance potion",
            "potion of disease resistance" }));
        set("blueprint", "disease resistance");
    }
}
