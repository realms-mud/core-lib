//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Runner Bean");
    set("short", "Runner Bean");
    set("aliases", ({ "bean", "runner bean" }));
    set("blueprint", "runner bean");
}
