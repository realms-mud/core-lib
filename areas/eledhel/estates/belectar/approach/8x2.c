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

    addDecorator("village road corner NW");

    addExit("north", "/areas/eledhel/estates/belectar/approach/8x1.c");
    addExit("west", "/areas/eledhel/estates/belectar/approach/7x2.c");
}
