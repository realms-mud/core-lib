//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cottonwood");
    set("short", "Cottonwood");
    set("aliases", ({ "wood", "cottonwood" }));
    set("blueprint", "cottonwood");
}
