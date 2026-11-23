//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/trees/willow-stand.c", "south");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "west");
    addItem("/lib/environment/items/objects/fox-tracks.c", "northwest");

    addDecorator("village road corner NE");

    addExit("north", "/areas/northern-road/north-gate/6x4.c");
    addExit("east", "/areas/northern-road/north-gate/7x5.c");
}
