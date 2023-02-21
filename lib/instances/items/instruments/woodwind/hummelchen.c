//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Hummelchen");
    set("short", "Hummelchen");
    set("aliases", ({ "hummelchen", "pipes" }));
    set("blueprint", "hummelchen");
}
