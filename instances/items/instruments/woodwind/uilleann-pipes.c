//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Uilleann Pipes");
        set("short", "Uilleann Pipes");
        set("aliases", ({ "uilleann pipes", "pipes" }));
        set("blueprint", "uilleann pipes");
    }
}
