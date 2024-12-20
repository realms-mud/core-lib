//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Great sword");
    set("short", "Great sword");
    set("aliases", ({ "sword", "two-handed sword", "greatsword", "great sword" }));
    set("blueprint", "great sword");
}
