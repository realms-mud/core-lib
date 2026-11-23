//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/trees/alder-stand.c", "south");

    addDecorator("village road corner NE");

    addExit("east", "/areas/northern-road/lower-northern-wilds/1x4.c");
    addExit("north", "/areas/northern-road/lower-northern-wilds/0x3.c");
}
