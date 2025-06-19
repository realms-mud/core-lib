//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Graphite ore");
    set("short", "Graphite ore");
    set("aliases", ({ "ore", "graphite ore", "graphite" }));
    set("blueprint", "graphite ore");
}
