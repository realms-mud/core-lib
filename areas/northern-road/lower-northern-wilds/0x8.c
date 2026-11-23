//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/landforms/ridge.c", "south");
    addFeature("/lib/environment/features/water/spring.c", "west");

    addDecorator("village road corner NE");

    addExit("east", "/areas/northern-road/lower-northern-wilds/1x8.c");
    addExit("north", "/areas/northern-road/lower-northern-wilds/0x7.c");
}
