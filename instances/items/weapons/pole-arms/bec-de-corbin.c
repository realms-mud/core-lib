//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Bec de Corbin");
        set("short", "Bec de Corbin");
        set("aliases", ({ "corbin", "bec" }));
        set("blueprint", "bec de corbin");
    }
}
