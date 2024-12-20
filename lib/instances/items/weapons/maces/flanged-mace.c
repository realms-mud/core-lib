//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Flanged mace");
    set("short", "Flanged mace");
    set("aliases", ({ "mace", "flanged mace" }));
    set("blueprint", "flanged mace");
}
