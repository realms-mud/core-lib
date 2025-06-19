//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Platinum ore");
    set("short", "Platinum ore");
    set("aliases", ({ "ore", "platinum ore", "platinum" }));
    set("blueprint", "platinum ore");
}
