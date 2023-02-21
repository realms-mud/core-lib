//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Skirt");
    set("short", "Skirt");
    set("aliases", ({ "clothing", "clothes", "skirt" }));
    set("blueprint", "skirt");
}
