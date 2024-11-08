//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Cannellini Bean");
    set("short", "Cannellini Bean");
    set("aliases", ({ "bean", "cannellini bean", "cannellini" }));
    set("blueprint", "cannellini bean");
}
