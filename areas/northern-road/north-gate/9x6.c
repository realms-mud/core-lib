//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/knoll.c", "east");
    addItem("/lib/environment/items/objects/fox-tracks.c", "south");

    addDecorator("village road corner NW");

    addExit("north", "/areas/northern-road/north-gate/9x5.c");
    addExit("west", "/areas/northern-road/north-gate/8x6.c");
}
