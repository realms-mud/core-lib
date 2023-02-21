//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Mulberry");
    set("short", "Mulberry (Wood)");
    set("aliases", ({ "wood", "mulberry" }));
    set("blueprint", "mulberry");
}
