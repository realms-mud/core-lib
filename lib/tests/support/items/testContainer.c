//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/container.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Box");
    set("short", "Box");
    set("aliases", ({ "box" }));
    set("long", "This is the box of weasels. It's neat.");
}
