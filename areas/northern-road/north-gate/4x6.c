//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/hillock.c", "south");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "southeast");

    addDecorator("village road T-north");

    addExit("north", "/areas/northern-road/north-gate/4x5.c");
    addExit("east", "/areas/northern-road/north-gate/5x6.c");
    addExit("west", "/areas/northern-road/north-gate/3x6.c");
}
