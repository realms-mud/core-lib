//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Sycamore Fruit");
    set("short", "Sycamore Fruit");
    set("aliases", ({ "sycamore fruit", "sycamore" }));
    set("blueprint", "sycamore fruit");
}
