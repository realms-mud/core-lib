//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Wild Rice");
    set("short", "Wild Rice");
    set("aliases", ({ "wild rice", "rice" }));
    set("blueprint", "wild rice");
}
