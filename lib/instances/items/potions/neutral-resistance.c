//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Neutral Resistance");
    set("short", "Potion of Neutral Resistance");
    set("aliases", ({ "neutral resistance", "potion", "neutral resistance potion",
        "potion of neutral resistance" }));
    set("blueprint", "neutral resistance potion");
}
