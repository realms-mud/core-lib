//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Mohair");
    set("short", "Mohair");
    set("aliases", ({ "cloth", "textile", "mohair" }));
    set("blueprint", "mohair");
}
