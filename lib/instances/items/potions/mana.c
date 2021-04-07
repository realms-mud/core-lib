//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Mana Potion");
    set("short", "Mana Potion");
    set("aliases", ({ "mana", "potion", "mana potion" }));
    set("blueprint", "mana potion");
}
