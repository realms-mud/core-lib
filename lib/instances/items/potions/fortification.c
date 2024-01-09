//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Fortification");
    set("short", "Potion of Fortification");
    set("aliases", ({ "fortification", "potion", "fortification potion",
        "potion of fortification" }));
    set("blueprint", "fortification potion");
}
