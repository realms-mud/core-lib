//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Deer leather");
    set("short", "Deer leather");
    set("aliases", ({ "leather", "deer leather" }));
    set("blueprint", "deer leather");
}
