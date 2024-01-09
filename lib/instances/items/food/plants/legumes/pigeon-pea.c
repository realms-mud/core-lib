//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Pigeon Pea");
    set("short", "Pigeon Pea");
    set("aliases", ({ "pea", "pigeon pea" }));
    set("blueprint", "pigeon pea");
}
