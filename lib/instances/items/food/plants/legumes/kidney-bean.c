//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Kidney Bean");
    set("short", "Kidney Bean");
    set("aliases", ({ "bean", "kidney bean" }));
    set("blueprint", "kidney bean");
}
