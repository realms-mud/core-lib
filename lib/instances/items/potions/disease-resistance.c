//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Disease Resistance");
    set("short", "Potion of Disease Resistance");
    set("aliases", ({ "disease resistance", "potion", "disease resistance potion",
        "potion of disease resistance" }));
    set("blueprint", "disease resistance potion");
}
