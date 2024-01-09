//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Lilac Flower");
    set("short", "Lilac Flower");
    set("aliases", ({ "lilac flower", "lilac" }));
    set("blueprint", "lilac flower");
}
