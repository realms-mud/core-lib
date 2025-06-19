//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Lead ore");
    set("short", "Lead ore");
    set("aliases", ({ "ore", "lead ore", "lead" }));
    set("blueprint", "lead ore");
}
