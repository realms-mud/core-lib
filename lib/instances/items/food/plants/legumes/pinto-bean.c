//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Pinto Bean");
    set("short", "Pinto Bean");
    set("aliases", ({ "bean", "pinto bean" }));
    set("blueprint", "pinto bean");
}
