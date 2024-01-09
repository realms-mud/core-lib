//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Winesap Apple");
    set("short", "Winesap Apple");
    set("aliases", ({ "winesap apple", "apple" }));
    set("blueprint", "winesap apple");
}
