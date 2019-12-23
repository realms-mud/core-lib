//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Bagpipes");
        set("short", "Bagpipes");
        set("aliases", ({ "bagpipes", "pipes" }));
        set("blueprint", "bagpipes");
    }
}
