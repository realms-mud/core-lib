//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Book");
    set("short", "Book");
    set("aliases", ({ "book" }));
    set("blueprint", "book");
}
