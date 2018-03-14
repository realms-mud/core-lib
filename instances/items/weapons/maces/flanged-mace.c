//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Flanged mace");
        set("short", "Flanged mace");
        set("aliases", ({ "mace", "flanged mace" }));
        set("blueprint", "flanged mace");
    }
}
