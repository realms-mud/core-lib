//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Crow Feather");
    set("short", "Crow Feather");
    set("aliases", ({ "feather", "crow feather" }));
    set("blueprint", "crow feather");
}
