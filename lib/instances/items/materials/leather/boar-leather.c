//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Boar leather");
    set("short", "Boar leather");
    set("aliases", ({ "leather", "boar leather" }));
    set("blueprint", "boar leather");
}
