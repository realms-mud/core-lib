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
    addFeature("/lib/environment/features/trees/alder-stand.c", "north");
    addFeature("/lib/environment/features/landforms/knoll.c", "south");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/hrondil-approaches/21x0.c");
    addExit("west", "/areas/northern-road/hrondil-approaches/19x0.c");
}
