//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Sycamore");
    set("short", "Sycamore");
    set("aliases", ({ "wood", "sycamore" }));
    set("blueprint", "sycamore");
}
