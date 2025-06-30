//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Elderberry");
    set("short", "Elderberry");
    set("aliases", ({ "elderberry", "berry" }));
    set("blueprint", "elderberry");
}
