//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("The road passes a low rise above the city fields");
    addDecorator("village east-west road");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("west", "/areas/eledhel/southwest-rural-five/12x9.c");
    addExit("east", "/areas/eledhel/southwest-rural-five/14x9.c");
}
