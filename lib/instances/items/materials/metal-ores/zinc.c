//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Zinc ore");
    set("short", "Zinc ore");
    set("aliases", ({ "ore", "zinc ore", "zinc" }));
    set("blueprint", "zinc ore");
}
