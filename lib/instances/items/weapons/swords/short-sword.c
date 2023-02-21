//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Short sword");
    set("short", "Short sword");
    set("aliases", ({ "sword", "shortsword", "short sword" }));
    set("blueprint", "short sword");
}
