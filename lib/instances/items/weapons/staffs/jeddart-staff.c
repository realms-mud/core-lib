//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Jeddart staff");
    set("short", "Jeddart staff");
    set("aliases", ({ "staff", "jeddart staff" }));
    set("blueprint", "jeddart staff");
}
