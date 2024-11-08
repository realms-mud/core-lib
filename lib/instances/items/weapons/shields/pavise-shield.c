//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Pavise shield");
    set("short", "Pavise shield");
    set("aliases", ({ "shield", "pavise shield" }));
    set("blueprint", "pavise shield");
}
