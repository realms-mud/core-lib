//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Dogwood");
    set("short", "Dogwood");
    set("aliases", ({ "wood", "dogwood" }));
    set("blueprint", "dogwood");
}
