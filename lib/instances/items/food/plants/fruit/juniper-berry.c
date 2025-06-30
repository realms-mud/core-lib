//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Juniper Berry");
    set("short", "Juniper Berry");
    set("aliases", ({ "juniper berry", "berry" }));
    set("blueprint", "juniper berry");
}
