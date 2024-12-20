//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Plate mail");
    set("short", "Plate mail");
    set("aliases", ({ "armor", "plate", "mail", "plate mail" }));
    set("blueprint", "plate mail");
}
