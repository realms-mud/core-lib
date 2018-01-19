//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Plate arm greaves");
        set("short", "Plate arm greaves");
        set("aliases", ({ "greaves", "arm greaves" }));
        set("blueprint", "plate arm greaves");
    }
}
