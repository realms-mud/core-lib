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
    addFeature("/lib/environment/features/trees/chokecherry-stand.c",
        "north");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "south");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/northern-manor/6x2.c");
    addExit("west", "/areas/northern-road/northern-manor/4x2.c");
}
