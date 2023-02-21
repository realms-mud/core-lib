//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Red Onion");
    set("short", "Red Onion");
    set("aliases", ({ "red onion", "onion" }));
    set("blueprint", "red onion");
}
