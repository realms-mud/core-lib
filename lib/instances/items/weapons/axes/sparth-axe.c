//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Sparth axe");
    set("short", "Sparth axe");
    set("aliases", ({ "axe", "sparth axe" }));
    set("blueprint", "sparth axe");
}
