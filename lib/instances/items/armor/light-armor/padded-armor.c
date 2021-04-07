//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Padded armor");
    set("short", "Padded armor");
    set("aliases", ({ "armor", "padded armor" }));
    set("blueprint", "padded armor");
}
