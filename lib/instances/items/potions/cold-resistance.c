//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Cold Resistance");
    set("short", "Potion of Cold Resistance");
    set("aliases", ({ "cold resistance", "potion", "cold resistance potion",
        "potion of cold resistance" }));
    set("blueprint", "cold resistance potion");
}
