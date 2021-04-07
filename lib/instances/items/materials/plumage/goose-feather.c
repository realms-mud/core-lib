//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Goose Feather");
    set("short", "Goose Feather");
    set("aliases", ({ "feather", "goose feather" }));
    set("blueprint", "goose feather");
}
