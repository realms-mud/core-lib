//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Hinged flail");
    set("short", "Hinged flail");
    set("aliases", ({ "flail", "hinged flail" }));
    set("blueprint", "hinged flail");
}
