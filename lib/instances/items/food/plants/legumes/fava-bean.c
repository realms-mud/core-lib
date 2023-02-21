//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Fava Bean");
    set("short", "Fava Bean");
    set("aliases", ({ "bean", "fava bean" }));
    set("blueprint", "fava bean");
}
