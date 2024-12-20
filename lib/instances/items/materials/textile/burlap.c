//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Burlap");
    set("short", "Burlap");
    set("aliases", ({ "cloth", "textile", "burlap" }));
    set("blueprint", "burlap");
}
