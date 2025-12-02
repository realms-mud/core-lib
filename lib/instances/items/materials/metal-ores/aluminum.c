//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Aluminum ore");
    set("short", "Aluminum ore");
    set("aliases", ({ "ore", "aluminum ore", "bauxite", "aluminum" }));
    set("blueprint", "aluminum ore");
}
