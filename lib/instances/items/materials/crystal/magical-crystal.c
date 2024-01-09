//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Magical crystal");
    set("short", "Magical crystal");
    set("aliases", ({ "crystal", "magical crystal" }));
    set("blueprint", "magical crystal");
}
