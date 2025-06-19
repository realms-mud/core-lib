//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Mithril ore");
    set("short", "Mithril ore");
    set("aliases", ({ "ore", "mithril ore", "mithril" }));
    set("blueprint", "mithril ore");
}
