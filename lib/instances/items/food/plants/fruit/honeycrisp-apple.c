//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Honeycrisp Apple");
    set("short", "Honeycrisp Apple");
    set("aliases", ({ "honeycrisp apple", "apple" }));
    set("blueprint", "honeycrisp apple");
}
