//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/water/stream.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/trees/willow-stand.c", "southwest");
    addItem("/lib/environment/items/objects/stone-pile.c", "northeast");

    addDecorator("village square");

    addExit("east", "/areas/northern-road/north-gate/4x5.c");
}
