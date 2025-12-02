//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Lupin Bean");
    set("short", "Lupin Bean");
    set("aliases", ({ "bean", "lupin bean" }));
    set("blueprint", "lupin bean");
}
