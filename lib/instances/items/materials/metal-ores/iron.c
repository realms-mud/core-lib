//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Iron ore");
    set("short", "Iron ore");
    set("aliases", ({ "ore", "iron ore", "iron" }));
    set("blueprint", "iron ore");
}
