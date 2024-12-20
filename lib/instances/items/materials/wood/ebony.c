//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Ebony");
    set("short", "Ebony (Wood)");
    set("aliases", ({ "wood", "ebony" }));
    set("blueprint", "ebony");
}
