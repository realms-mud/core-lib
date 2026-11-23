//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/hummock.c", "south");
    addFeature("/lib/environment/features/water/stream.c", "east");

    addDecorator("village road corner NW");

    addExit("north", "/areas/northern-road/belathon-eolach/24x1.c");
    addExit("west", "/areas/northern-road/belathon-eolach/23x2.c");
}
