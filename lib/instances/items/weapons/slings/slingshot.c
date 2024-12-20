//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Slingshot");
    set("short", "Slingshot");
    set("aliases", ({ "sling", "slingshot" }));
    set("blueprint", "slingshot");
}
