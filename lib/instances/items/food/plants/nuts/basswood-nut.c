//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Basswood Nut");
    set("short", "Basswood Nut");
    set("aliases", ({ "basswood nut", "nut" }));
    set("blueprint", "basswood nut");
}
