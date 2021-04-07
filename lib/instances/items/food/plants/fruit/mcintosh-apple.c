//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "McIntosh Apple");
    set("short", "McIntosh Apple");
    set("aliases", ({ "mcintosh apple", "apple" }));
    set("blueprint", "mcintosh apple");
}
