//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Yew Cone");
    set("short", "Yew Cone");
    set("aliases", ({ "yew cone", "cone" }));
    set("blueprint", "yew cone");
}
