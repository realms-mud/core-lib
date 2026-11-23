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
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "north");
    addItem("/lib/environment/items/objects/wooden-fence.c", "south");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/north-gate/3x3.c");
    addExit("west", "/areas/northern-road/north-gate/1x3.c");
}
