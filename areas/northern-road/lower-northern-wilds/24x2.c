//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "south");

    addDecorator("village road corner NW");

    addExit("west", "/areas/northern-road/lower-northern-wilds/23x2.c");
    addExit("north", "/areas/northern-road/lower-northern-wilds/24x1.c");
}
