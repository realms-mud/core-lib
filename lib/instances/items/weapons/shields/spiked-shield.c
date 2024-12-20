//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Spiked shield");
    set("short", "Spiked shield");
    set("aliases", ({ "shield", "spiked shield" }));
    set("blueprint", "spiked shield");
}
