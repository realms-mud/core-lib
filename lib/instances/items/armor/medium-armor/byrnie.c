//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Byrnie");
    set("short", "Byrnie");
    set("aliases", ({ "byrnie", "mail", "armor", "chain", "chainmail" }));
    set("blueprint", "byrnie");
}
