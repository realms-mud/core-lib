//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cutlass");
    set("short", "Cutlass");
    set("aliases", ({ "sword", "cutlass" }));
    set("blueprint", "cutlass");
}
