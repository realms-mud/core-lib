//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "south");
    addFeature("/lib/environment/features/trees/oak-stand.c", "northeast");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/north-gate/2x4.c");
    addExit("west", "/areas/northern-road/north-gate/0x4.c");
}
