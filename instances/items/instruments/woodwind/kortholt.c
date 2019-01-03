//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Kortholt");
        set("short", "Kortholt");
        set("aliases", ({ "kortholt", "windcap", "wind cap", "instrument" }));
        set("blueprint", "kortholt");
    }
}
