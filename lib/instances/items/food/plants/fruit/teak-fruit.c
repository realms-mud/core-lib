//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Teak Fruit");
    set("short", "Teak Fruit");
    set("aliases", ({ "teak fruit", "teak" }));
    set("blueprint", "teak fruit");
}
