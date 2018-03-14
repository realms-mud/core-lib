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
        set("name", "Hauberk");
        set("short", "Hauberk");
        set("aliases", ({ "chainmail", "armor", "hauberk" }));
        set("blueprint", "hauberk");
    }
}
