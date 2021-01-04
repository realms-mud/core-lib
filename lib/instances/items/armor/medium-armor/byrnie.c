//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Byrnie");
        set("short", "Byrnie");
        set("aliases", ({ "byrnie", "mail", "armor", "chain", "chainmail" }));
        set("blueprint", "byrnie");
    }
}
