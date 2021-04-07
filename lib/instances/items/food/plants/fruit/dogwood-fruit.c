//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Dogwood Fruit");
    set("short", "Dogwood Fruit");
    set("aliases", ({ "dogwood fruit", "dogwood" }));
    set("blueprint", "dogwood fruit");
}
