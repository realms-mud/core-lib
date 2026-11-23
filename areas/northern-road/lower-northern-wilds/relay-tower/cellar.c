//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addItem("/lib/environment/items/objects/stone-pile.c", "north");

    addExit("up", "/areas/northern-road/lower-northern-wilds/18x8.c");
}
