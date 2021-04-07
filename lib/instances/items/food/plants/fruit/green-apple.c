//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Green Apple");
    set("short", "Green Apple");
    set("aliases", ({ "green apple", "apple" }));
    set("blueprint", "green apple");
}
