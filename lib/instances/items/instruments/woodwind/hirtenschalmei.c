//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Hirtenschalmei");
    set("short", "Hirtenschalmei");
    set("aliases", ({ "hirtenschalmei", "windcap", "wind cap", "instrument" }));
    set("blueprint", "hirtenschalmei");
}
