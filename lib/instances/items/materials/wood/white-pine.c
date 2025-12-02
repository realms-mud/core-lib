//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "White Pine");
    set("short", "White Pine");
    set("aliases", ({ "wood", "white pine", "pine" }));
    set("blueprint", "white pine");
}
