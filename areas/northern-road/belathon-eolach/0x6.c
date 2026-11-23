//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/landforms/knoll.c", "north");
    addFeature("/lib/environment/features/water/spring.c", "west");

    addDecorator("village road corner SE");

    addExit("east", "/areas/northern-road/belathon-eolach/1x6.c");
    addExit("south", "/areas/northern-road/belathon-eolach/0x7.c");
}
