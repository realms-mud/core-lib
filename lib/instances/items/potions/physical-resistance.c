//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Physical Resistance");
    set("short", "Potion of Physical Resistance");
    set("aliases", ({ "physical resistance", "potion", "physical resistance potion",
        "potion of physical resistance" }));
    set("blueprint", "physical resistance potion");
}
