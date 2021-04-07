//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Recorder");
    set("short", "Recorder");
    set("aliases", ({ "recorder", "windcap", "wind cap", "instrument" }));
    set("blueprint", "recorder");
}
