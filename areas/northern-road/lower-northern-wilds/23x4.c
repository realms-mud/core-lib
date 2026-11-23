//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/alder-stand.c", "south");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/lower-northern-wilds/24x4.c");
    addExit("west", "/areas/northern-road/lower-northern-wilds/22x4.c");
}
