//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Malorn");
    set("short", "Malorn");
    set("aliases", ({ "wood", "malorn" }));
    set("blueprint", "malorn");
}
