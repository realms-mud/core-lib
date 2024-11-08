//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Scape");
    set("short", "Scape");
    set("aliases", ({ "scape", "garlic" }));
    set("blueprint", "scape");
}
