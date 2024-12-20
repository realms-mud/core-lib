//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Hard leather");
    set("short", "Hard leather");
    set("aliases", ({ "leather", "armor", "hard leather" }));
    set("blueprint", "hard leather");
}
