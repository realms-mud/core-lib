//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Green Bean");
    set("short", "Green Bean");
    set("aliases", ({ "bean", "green bean" }));
    set("blueprint", "green bean");
}
