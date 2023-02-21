//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Potion of Constitution");
    set("short", "Potion of Constitution");
    set("aliases", ({ "constitution", "potion", "constitution potion",
        "potion of constitution" }));
    set("blueprint", "constitution potion");
}
