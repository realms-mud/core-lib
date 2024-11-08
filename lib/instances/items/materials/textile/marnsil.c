//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Marnsil");
    set("short", "Marnsil");
    set("aliases", ({ "cloth", "textile", "marnsil" }));
    set("blueprint", "marnsil");
}
