//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Long sword");
    set("short", "Long sword");
    set("aliases", ({ "sword", "longsword", "long sword" }));
    set("blueprint", "long sword");
}
