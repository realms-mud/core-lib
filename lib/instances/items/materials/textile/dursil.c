//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Dursil");
    set("short", "Dursil");
    set("aliases", ({ "cloth", "textile", "dursil" }));
    set("blueprint", "dursil");
}
