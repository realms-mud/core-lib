//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Brigandine");
    set("short", "Brigandine");
    set("aliases", ({ "armor", "brigandine" }));
    set("blueprint", "brigandine");
}
