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
        set("name", "Horseman's pick");
        set("short", "Horseman's pick");
        set("aliases", ({ "hammer", "pick", "horseman's pick", "horsemans pick" }));
        set("blueprint", "horseman's pick");
    }
}
