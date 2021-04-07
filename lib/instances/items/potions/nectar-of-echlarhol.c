//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Nectar of Echlarhol");
    set("short", "Nectar of Echlarhol");
    set("aliases", ({ "nectar", "potion", "nectar of echlarhol" }));
    set("blueprint", "nectar of echlarhol");
}
