//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/water/field-drain.c", "north");
    addFeature("/lib/environment/features/trees/alder-stand.c", "east");
    addItem("/lib/environment/items/objects/stone-pile.c", "southwest");
    addObject("/areas/northern-road/north-gate/characters/daereth.c");

    addDecorator("village road corner SW");

    addExit("south", "/areas/northern-road/north-gate/4x6.c");
    addExit("west", "/areas/northern-road/north-gate/3x5.c");
}
