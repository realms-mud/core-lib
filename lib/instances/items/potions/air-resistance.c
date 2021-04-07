//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Air Resistance");
    set("short", "Potion of Air Resistance");
    set("aliases", ({ "air resistance", "potion", "air resistance potion",
        "potion of air resistance" }));
    set("blueprint", "air resistance potion");
}
