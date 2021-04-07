//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Willow Bark");
    set("short", "Willow Bark");
    set("aliases", ({ "willow bark", "bark", "willow" }));
    set("blueprint", "willow bark");
}
