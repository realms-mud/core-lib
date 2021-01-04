//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Qiviut");
        set("short", "Qiviut");
        set("aliases", ({ "cloth", "textile", "qiviut" }));
        set("blueprint", "qiviut");
    }
}
