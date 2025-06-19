//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Nickel ore");
    set("short", "Nickel ore");
    set("aliases", ({ "ore", "nickel ore", "nickel" }));
    set("blueprint", "nickel ore");
}
