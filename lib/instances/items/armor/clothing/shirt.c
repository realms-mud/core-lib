//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Shirt");
    set("short", "Shirt");
    set("aliases", ({ "clothing", "clothes", "shirt" }));
    set("blueprint", "shirt");
}
