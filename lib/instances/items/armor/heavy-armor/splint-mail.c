//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Splint mail");
        set("short", "Splint mail");
        set("aliases", ({ "armor", "splint", "mail", "splint mail" }));
        set("blueprint", "splint mail");
    }
}
