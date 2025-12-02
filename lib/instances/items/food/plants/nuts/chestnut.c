//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Chestnut");
    set("short", "Chestnut");
    set("aliases", ({ "chestnut", "nut" }));
    set("blueprint", "chestnut nut");
}
