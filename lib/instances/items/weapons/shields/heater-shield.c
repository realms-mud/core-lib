//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Heater shield");
    set("short", "Heater shield");
    set("aliases", ({ "shield", "heater shield" }));
    set("blueprint", "heater shield");
}
