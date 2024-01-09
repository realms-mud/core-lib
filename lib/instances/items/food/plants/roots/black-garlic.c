//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Black Garlic");
    set("short", "Black Garlic");
    set("aliases", ({ "black garlic", "garlic" }));
    set("blueprint", "black garlic");
}
