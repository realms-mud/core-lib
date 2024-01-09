//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Qiviut");
    set("short", "Qiviut");
    set("aliases", ({ "cloth", "textile", "qiviut" }));
    set("blueprint", "qiviut");
}
