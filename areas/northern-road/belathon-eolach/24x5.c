//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/trees/alder-stand.c", "east");
    addItem("/lib/environment/items/objects/stone-pile.c", "southwest");

    addDecorator("village north-south road");

    addExit("north", "/areas/northern-road/belathon-eolach/24x4.c");
    addExit("south", "/areas/northern-road/belathon-eolach/24x6.c");
}
