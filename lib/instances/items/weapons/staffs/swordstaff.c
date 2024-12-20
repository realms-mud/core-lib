//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Swordstaff");
    set("short", "Swordstaff");
    set("aliases", ({ "staff", "swordstaff", "sword staff" }));
    set("blueprint", "swordstaff");
}
