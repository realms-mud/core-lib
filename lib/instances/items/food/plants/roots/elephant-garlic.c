//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Elephant Garlic");
    set("short", "Elephant Garlic");
    set("aliases", ({ "elephant garlic", "garlic" }));
    set("blueprint", "elephant garlic");
}
