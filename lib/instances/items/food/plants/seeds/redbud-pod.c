//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Redbud Pod");
    set("short", "Redbud Pod");
    set("aliases", ({ "redbud pod", "pod", "seed pod", "seed" }));
    set("blueprint", "redbud pod");
}
