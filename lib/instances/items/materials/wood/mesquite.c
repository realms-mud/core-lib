//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Mesquite");
    set("short", "Mesquite");
    set("aliases", ({ "wood", "mesquite" }));
    set("blueprint", "mesquite");
}
