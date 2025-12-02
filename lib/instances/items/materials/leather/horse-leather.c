//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Horse leather");
    set("short", "Horse leather");
    set("aliases", ({ "leather", "horse leather" }));
    set("blueprint", "horse leather");
}
