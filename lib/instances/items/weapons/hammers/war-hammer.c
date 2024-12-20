//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "War hammer");
    set("short", "War hammer");
    set("aliases", ({ "hammer", "warhammer", "war hammer" }));
    set("blueprint", "war hammer");
}
