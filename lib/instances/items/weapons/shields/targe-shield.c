//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Targe shield");
    set("short", "Targe shield");
    set("aliases", ({ "shield", "targe shield" }));
    set("blueprint", "targe shield");
}
