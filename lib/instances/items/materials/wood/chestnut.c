//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Chestnut");
    set("short", "Chestnut");
    set("aliases", ({ "wood", "chestnut" }));
    set("blueprint", "chestnut");
}
