//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/plants/common-root-beds.c",
        "south");
    addFeature("/lib/environment/features/water/field-drain.c", "east");

    addDecorator("village road corner NW");

    addExit("west", "/areas/northern-road/hrondil-approaches/23x2.c");
    addExit("north", "/areas/northern-road/hrondil-approaches/24x1.c");
}
