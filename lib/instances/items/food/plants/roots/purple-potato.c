//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Purple Potato");
    set("short", "Purple Potato");
    set("aliases", ({ "purple potato", "potato" }));
    set("blueprint", "purple potato");
}
