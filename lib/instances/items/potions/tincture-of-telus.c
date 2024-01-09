//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Tincture of Telus");
    set("short", "Tincture of Telus");
    set("aliases", ({ "tincture", "potion", "tincture of telus" }));
    set("blueprint", "tincture of telus");
}
