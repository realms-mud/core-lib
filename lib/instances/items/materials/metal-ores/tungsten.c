//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Tungsten ore");
    set("short", "Tungsten ore");
    set("aliases", ({ "ore", "tungsten ore", "tungsten" }));
    set("blueprint", "tungsten ore");
}
