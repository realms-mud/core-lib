//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/common-grain-strips.c",
        "north");
    addFeature("/lib/environment/features/water/field-drain.c", "east");

    addDecorator("village road corner SW");

    addExit("south", "/areas/northern-road/north-gate/9x1.c");
    addExit("west", "/areas/northern-road/north-gate/8x0.c");
}
