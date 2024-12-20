//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cranequin crossbow");
    set("short", "Cranequin crossbow");
    set("aliases", ({ "crossbow", "cranequin crossbow" }));
    set("blueprint", "cranequin crossbow");
}
