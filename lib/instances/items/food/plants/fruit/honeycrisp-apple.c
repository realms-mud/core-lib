//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Honeycrisp Apple");
        set("short", "Honeycrisp Apple");
        set("aliases", ({ "honeycrisp apple", "apple" }));
        set("blueprint", "honeycrisp apple");
    }
}
