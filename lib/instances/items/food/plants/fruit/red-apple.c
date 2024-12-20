//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Red Apple");
    set("short", "Red Apple");
    set("aliases", ({ "red apple", "apple" }));
    set("blueprint", "red apple");
}
