//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Copper ore");
    set("short", "Copper ore");
    set("aliases", ({ "ore", "copper ore", "copper" }));
    set("blueprint", "copper ore");
}
