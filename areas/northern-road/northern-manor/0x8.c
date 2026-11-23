//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/landforms/hillock.c", "south");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "west");

    addDecorator("village road corner NE");

    addExit("north", "/areas/northern-road/northern-manor/0x7.c");
    addExit("east", "/areas/northern-road/northern-manor/1x8.c");
}
