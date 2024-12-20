//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Breastplate");
    set("short", "Breastplate");
    set("aliases", ({ "armor", "breastplate", "plate" }));
    set("blueprint", "breastplate");
}
