//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Quarterstaff");
    set("short", "Quarterstaff");
    set("aliases", ({ "staff", "quarterstaff" }));
    set("blueprint", "quarterstaff");
}
