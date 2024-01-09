//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Pigeon Feather");
    set("short", "Pigeon Feather");
    set("aliases", ({ "feather", "pigeon feather" }));
    set("blueprint", "pigeon feather");
}
