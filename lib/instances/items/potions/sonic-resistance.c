//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Sonic Resistance");
    set("short", "Potion of Sonic Resistance");
    set("aliases", ({ "sonic resistance", "potion", "sonic resistance potion",
        "potion of sonic resistance" }));
    set("blueprint", "sonic resistance potion");
}
