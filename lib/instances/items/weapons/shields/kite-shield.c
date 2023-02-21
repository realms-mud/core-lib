//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Kite shield");
    set("short", "Kite shield");
    set("aliases", ({ "shield", "kite shield" }));
    set("blueprint", "kite shield");
}
