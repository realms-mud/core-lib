//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Boiled leather");
        set("short", "Boiled leather");
        set("aliases", ({ "leather", "armor", "boiled leather" }));
        set("blueprint", "boiled leather");
    }
}
