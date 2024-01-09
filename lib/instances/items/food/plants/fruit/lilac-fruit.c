//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Lilac Fruit");
    set("short", "Lilac Fruit");
    set("aliases", ({ "lilac fruit", "lilac" }));
    set("blueprint", "lilac fruit");
}
