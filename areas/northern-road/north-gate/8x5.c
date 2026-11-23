//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/water/stream.c", "south");
    addFeature("/lib/environment/features/trees/willow-stand.c", "east");
    addItem("/lib/environment/items/objects/fox-tracks.c", "northeast");

    addDecorator("village square");

    addExit("west", "/areas/northern-road/north-gate/7x5.c");
}
