//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Healing Potion");
    set("short", "Healing Potion");
    set("aliases", ({ "healing", "potion", "healing potion" }));
    set("blueprint", "healing potion");
}
