//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Claymore");
        set("short", "Claymore");
        set("aliases", ({ "sword", "two-handed sword", "claymore" }));
        set("blueprint", "claymore");
    }
}
