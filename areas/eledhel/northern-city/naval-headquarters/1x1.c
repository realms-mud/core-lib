//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/guard-room.c");
    setShortDescription("The signal watch above the northern docks");
    addItem("/lib/environment/items/marine/ships-bell.c", "east");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addObject("/areas/eledhel/northern-city/characters/naval-watch.c");
    addExit("south", "/areas/eledhel/northern-city/naval-headquarters/1x0.c");
}
