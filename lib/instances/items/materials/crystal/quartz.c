//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Quartz");
    set("short", "Quartz");
    set("aliases", ({ "gem", "quartz" }));
    set("blueprint", "quartz");
}
