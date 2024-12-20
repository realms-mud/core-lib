//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Lima Bean");
    set("short", "Lima Bean");
    set("aliases", ({ "bean", "lima bean" }));
    set("blueprint", "lima bean");
}
