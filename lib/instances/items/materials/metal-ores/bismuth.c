//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bismuth ore");
    set("short", "Bismuth ore");
    set("aliases", ({ "ore", "bismuth ore", "bismuth" }));
    set("blueprint", "bismuth ore");
}
