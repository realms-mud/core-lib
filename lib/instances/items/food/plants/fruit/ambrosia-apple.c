//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Ambrosia Apple");
    set("short", "Ambrosia Apple");
    set("aliases", ({ "ambrosia apple", "apple" }));
    set("blueprint", "ambrosia apple");
}
