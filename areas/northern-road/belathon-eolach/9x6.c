//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/knoll.c", "north");
    addFeature("/lib/environment/features/water/spring.c", "south");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/belathon-eolach/10x6.c");
    addExit("west", "/areas/northern-road/belathon-eolach/8x6.c");
}
