//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Composite bow");
    set("short", "Composite bow");
    set("aliases", ({ "bow", "composite bow" }));
    set("blueprint", "composite bow");
}
