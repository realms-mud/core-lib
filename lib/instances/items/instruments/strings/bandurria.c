//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bandurria");
    set("short", "Bandurria");
    set("aliases", ({ "bandurria", "strings", "instrument" }));
    set("blueprint", "bandurria");
}
