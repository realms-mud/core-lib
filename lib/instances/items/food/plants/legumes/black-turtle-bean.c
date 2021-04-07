//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "black Turtle Bean");
    set("short", "black Turtle Bean");
    set("aliases", ({ "bean", "black turtle bean", "turtle bean" }));
    set("blueprint", "black turtle bean");
}
