//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Duck Feather");
    set("short", "Duck Feather");
    set("aliases", ({ "feather", "duck feather" }));
    set("blueprint", "duck feather");
}
