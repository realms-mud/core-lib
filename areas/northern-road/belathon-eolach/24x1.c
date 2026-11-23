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
    addFeature("/lib/environment/features/trees/oak-stand.c", "east");
    addItem("/lib/environment/items/objects/stone-pile.c", "west");

    addDecorator("village north-south road");

    addExit("north", "/areas/northern-road/belathon-eolach/24x0.c");
    addExit("south", "/areas/northern-road/belathon-eolach/24x2.c");
}
