//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Osmium ore");
    set("short", "Osmium ore");
    set("aliases", ({ "ore", "osmium ore", "osmium" }));
    set("blueprint", "osmium ore");
}
