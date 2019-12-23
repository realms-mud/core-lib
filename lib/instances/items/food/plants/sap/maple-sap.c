//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Maple Sap");
        set("short", "Maple Sap");
        set("aliases", ({ "maple sap", "sap" }));
        set("blueprint", "maple sap");
    }
}
