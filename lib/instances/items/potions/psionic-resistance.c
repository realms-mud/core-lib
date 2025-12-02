//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Psionic Resistance");
    set("short", "Potion of Psionic Resistance");
    set("aliases", ({ "psionic resistance", "potion", "psionic resistance potion",
        "potion of psionic resistance" }));
    set("blueprint", "psionic resistance potion");
}
