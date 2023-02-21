//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cow leather");
    set("short", "Cow leather");
    set("aliases", ({ "leather", "cow leather" }));
    set("blueprint", "cow leather");
}
