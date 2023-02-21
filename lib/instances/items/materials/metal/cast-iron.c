//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cast iron");
    set("short", "Cast iron");
    set("aliases", ({ "metal", "cast iron", "iron" }));
    set("blueprint", "cast iron");
}
