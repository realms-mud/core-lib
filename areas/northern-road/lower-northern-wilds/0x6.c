//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-mountain.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "north");
    addFeature("/lib/environment/features/water/stream.c", "west");

    addDecorator("village road corner SE");

    addExit("east", "/areas/northern-road/lower-northern-wilds/1x6.c");
    addExit("south", "/areas/northern-road/lower-northern-wilds/0x7.c");
}
