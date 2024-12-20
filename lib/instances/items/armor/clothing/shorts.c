//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Shorts");
    set("short", "Shorts");
    set("aliases", ({ "clothing", "clothes", "shorts" }));
    set("blueprint", "shorts");
}
