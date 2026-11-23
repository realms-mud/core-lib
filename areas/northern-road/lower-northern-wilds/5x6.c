//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-mountain.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/crag.c", "south");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "north");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/lower-northern-wilds/6x6.c");
    addExit("west", "/areas/northern-road/lower-northern-wilds/4x6.c");
}
