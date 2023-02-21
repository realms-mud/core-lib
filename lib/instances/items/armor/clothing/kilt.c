//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Kilt");
    set("short", "Kilt");
    set("aliases", ({ "clothing", "clothes", "kilt" }));
    set("blueprint", "kilt");
}
