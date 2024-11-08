//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Short bow");
    set("short", "Short bow");
    set("aliases", ({ "bow", "short bow" }));
    set("blueprint", "short bow");
}
