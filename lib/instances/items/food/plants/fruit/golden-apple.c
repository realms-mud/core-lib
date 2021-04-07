//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Golden Apple");
    set("short", "Golden Apple");
    set("aliases", ({ "golden apple", "apple" }));
    set("blueprint", "golden apple");
}
