//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Mahogany Fruit");
    set("short", "Mahogany Fruit");
    set("aliases", ({ "mahogany fruit", "mahogany" }));
    set("blueprint", "mahogany fruit");
}
