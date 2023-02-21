//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bastard sword");
    set("short", "Bastard sword");
    set("aliases", ({ "sword", "bastardsword", "bastard sword" }));
    set("blueprint", "bastard sword");
}
