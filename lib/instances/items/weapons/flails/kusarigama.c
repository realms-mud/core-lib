//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Kusarigama");
    set("short", "Kusarigama");
    set("aliases", ({ "flail", "kusarigama" }));
    set("blueprint", "kusarigama");
}
