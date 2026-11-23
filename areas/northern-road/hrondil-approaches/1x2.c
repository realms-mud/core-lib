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
    addFeature("/lib/environment/features/water/field-drain.c", "north");
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "south");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/hrondil-approaches/2x2.c");
    addExit("west", "/areas/northern-road/hrondil-approaches/0x2.c");
}
