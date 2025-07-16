//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Bird's Eye Chili");
    set("short", "Bird's Eye Chili");
    set("aliases", ({ "pepper", "chili", "bird's eye chili" }));
    set("blueprint", "bird's eye chili");
}
