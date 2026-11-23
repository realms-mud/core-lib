//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/hillock.c", "east");
    addFeature("/lib/environment/features/trees/yew-stand.c", "south");
    addFeature("/lib/environment/features/trees/ash-stand.c", "north");
    addObject("/areas/eledhel/estates/eolach/characters/archer.c");

    addDecorator("village road corner NW");

    addExit("north", "/areas/eledhel/estates/eolach/approach/8x0.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/7x1.c");
}
