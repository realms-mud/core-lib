//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cashmere");
    set("short", "Cashmere");
    set("aliases", ({ "cloth", "textile", "cashmere" }));
    set("blueprint", "cashmere");
}
