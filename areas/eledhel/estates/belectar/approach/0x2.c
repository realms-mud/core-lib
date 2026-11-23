//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "west");

    addDecorator("village road corner SE");

    addExit("east", "/areas/eledhel/estates/belectar/approach/1x2.c");
    addExit("south", "/areas/eledhel/estates/belectar/approach/0x3.c");
}
