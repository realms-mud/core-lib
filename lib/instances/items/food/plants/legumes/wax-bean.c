//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Wax Bean");
    set("short", "Wax Bean");
    set("aliases", ({ "bean", "wax bean" }));
    set("blueprint", "wax bean");
}
