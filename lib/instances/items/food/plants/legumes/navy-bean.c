//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Navy Bean");
    set("short", "Navy Bean");
    set("aliases", ({ "bean", "navy bean" }));
    set("blueprint", "navy bean");
}
