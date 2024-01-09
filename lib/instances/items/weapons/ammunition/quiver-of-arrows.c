//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/ammunition.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "quiver");
    set("short", "A quiver");
    set("ammunition type", "arrow");
    set("max capacity", 24);
    set("quantity", 24);
}
