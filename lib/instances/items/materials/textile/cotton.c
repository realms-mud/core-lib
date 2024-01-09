//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cotton");
    set("short", "Cotton");
    set("aliases", ({ "cloth", "textile", "cotton" }));
    set("blueprint", "cotton");
}
