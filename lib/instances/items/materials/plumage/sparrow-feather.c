//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Sparrow Feather");
    set("short", "Sparrow Feather");
    set("aliases", ({ "feather", "sparrow feather" }));
    set("blueprint", "sparrow feather");
}
