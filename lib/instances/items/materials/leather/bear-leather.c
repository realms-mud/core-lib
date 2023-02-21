//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bear leather");
    set("short", "Bear leather");
    set("aliases", ({ "leather", "bear leather" }));
    set("blueprint", "bear leather");
}
