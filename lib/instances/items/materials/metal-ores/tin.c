//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Tin ore");
    set("short", "Tin ore");
    set("aliases", ({ "ore", "tin ore", "tin" }));
    set("blueprint", "tin ore");
}
