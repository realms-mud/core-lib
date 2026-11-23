//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The entry hall of the Eledhel naval headquarters");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addItem("/lib/environment/items/marine/ships-bell.c", "east");
    addExit("south", "/areas/eledhel/northern-city/23x8.c");
    addExit("east", "/areas/eledhel/northern-city/naval-headquarters/1x0.c");
    addExit("down", "/areas/eledhel/northern-city/naval-headquarters/0x1.c");
}
