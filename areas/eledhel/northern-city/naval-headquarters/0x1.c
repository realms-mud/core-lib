//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The naval stores and quartermaster's room");
    addItem("/lib/environment/items/military/supply-crate.c", "north");
    addItem("/lib/environment/items/marine/cargo-net.c", "east");
    addObject("/areas/eledhel/northern-city/characters/naval-quartermaster.c");
    addExit("up", "/areas/eledhel/northern-city/naval-headquarters/0x0.c");
    addExit("down", "/areas/eledhel/under-city/naval-branch/23x8.c");
}
