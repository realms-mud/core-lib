//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Sabre");
    set("short", "Sabre");
    set("aliases", ({ "sword", "saber", "sabre" }));
    set("blueprint", "sabre");
}
