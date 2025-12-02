//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Tulip Tree");
    set("short", "Tulip Tree");
    set("aliases", ({ "wood", "tulip tree", "tulip" }));
    set("blueprint", "tulip tree");
}
