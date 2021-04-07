//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Sweet Onion");
    set("short", "Sweet Onion");
    set("aliases", ({ "sweet onion", "onion" }));
    set("blueprint", "sweet onion");
}
