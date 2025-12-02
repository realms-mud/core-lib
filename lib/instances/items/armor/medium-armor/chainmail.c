//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Chainmail");
    set("short", "Chainmail");
    set("aliases", ({ "mail", "armor", "chainmail" }));
    set("blueprint", "chainmail");
}
