//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bec de Corbin");
    set("short", "Bec de Corbin");
    set("aliases", ({ "corbin", "bec", "bec de corbin" }));
    set("blueprint", "bec de corbin");
}
