//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Laminar armor");
    set("short", "Laminar armor");
    set("aliases", ({ "armor", "laminar", "laminar armor" }));
    set("blueprint", "laminar armor");
}
