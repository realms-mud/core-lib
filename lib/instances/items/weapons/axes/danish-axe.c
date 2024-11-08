//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Danish axe");
    set("short", "Danish axe");
    set("aliases", ({ "axe", "danish axe" }));
    set("blueprint", "danish axe");
}
