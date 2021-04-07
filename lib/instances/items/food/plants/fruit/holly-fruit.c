//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Holly Fruit");
    set("short", "Holly Fruit");
    set("aliases", ({ "holly fruit", "holly" }));
    set("blueprint", "holly fruit");
}
