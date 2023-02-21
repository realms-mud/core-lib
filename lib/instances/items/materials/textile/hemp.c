//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Hemp");
    set("short", "Hemp");
    set("aliases", ({ "cloth", "textile", "hemp" }));
    set("blueprint", "hemp");
}
