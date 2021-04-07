//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Wolf leather");
    set("short", "Wolf leather");
    set("aliases", ({ "leather", "wolf leather" }));
    set("blueprint", "wolf leather");
}
