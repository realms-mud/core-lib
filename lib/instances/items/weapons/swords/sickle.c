//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Sickle");
    set("short", "Sickle");
    set("aliases", ({ "sword", "short sword", "sickle" }));
    set("blueprint", "sickle");
}
