//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Mung Bean");
    set("short", "Mung Bean");
    set("aliases", ({ "bean", "mung bean" }));
    set("blueprint", "mung bean");
}
