//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/barley-field.c", "south");
    addFeature("/lib/environment/features/landforms/hill.c", "north");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/hrondil-approaches/15x2.c");
    addExit("west", "/areas/northern-road/hrondil-approaches/13x2.c");
}
