//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Intelligence");
    set("short", "Potion of Intelligence");
    set("aliases", ({ "intelligence", "potion", "intelligence potion",
        "potion of intelligence" }));
    set("blueprint", "intelligence potion");
}
