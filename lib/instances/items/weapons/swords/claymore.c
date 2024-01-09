//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Claymore");
    set("short", "Claymore");
    set("aliases", ({ "sword", "two-handed sword", "claymore" }));
    set("blueprint", "claymore");
}
