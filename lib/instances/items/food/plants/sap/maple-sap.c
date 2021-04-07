//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Maple Sap");
    set("short", "Maple Sap");
    set("aliases", ({ "maple sap", "sap" }));
    set("blueprint", "maple sap");
}
