//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Trombone");
        set("short", "Trombone");
        set("aliases", ({ "trombone", "brass", "wind cap", "instrument" }));
        set("blueprint", "trombone");
    }
}
