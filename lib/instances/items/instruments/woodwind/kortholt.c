//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Kortholt");
    set("short", "Kortholt");
    set("aliases", ({ "kortholt", "windcap", "wind cap", "instrument" }));
    set("blueprint", "kortholt");
}
