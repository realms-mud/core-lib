//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Recurve bow");
    set("short", "Recurve bow");
    set("aliases", ({ "bow", "recurve bow" }));
    set("blueprint", "recurve bow");
}
