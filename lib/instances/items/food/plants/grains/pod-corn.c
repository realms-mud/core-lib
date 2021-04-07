//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Pod Corn");
    set("short", "Pod Corn");
    set("aliases", ({ "pod corn", "corn" }));
    set("blueprint", "pod corn");
}
