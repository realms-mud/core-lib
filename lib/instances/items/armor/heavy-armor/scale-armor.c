//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Scale armor");
    set("short", "Scale armor");
    set("aliases", ({ "armor", "scale", "scale armor" }));
    set("blueprint", "scale armor");
}
