//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Charisma");
    set("short", "Potion of Charisma");
    set("aliases", ({ "charisma", "potion", "charisma potion",
        "potion of charisma" }));
    set("blueprint", "charisma potion");
}
