//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Yellow Onion");
    set("short", "Yellow Onion");
    set("aliases", ({ "yellow onion", "onion" }));
    set("blueprint", "yellow onion");
}
