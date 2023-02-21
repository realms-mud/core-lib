//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Meteoric iron");
    set("short", "Meteoric iron");
    set("aliases", ({ "iron" }));
    set("aliases", ({ "metal", "meteoric iron", "iron" }));
    set("blueprint", "meteoric iron");
}
