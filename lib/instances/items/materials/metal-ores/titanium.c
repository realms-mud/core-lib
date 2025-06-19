//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Titanium ore");
    set("short", "Titanium ore");
    set("aliases", ({ "ore", "titanium ore", "titanium" }));
    set("blueprint", "titanium ore");
}
