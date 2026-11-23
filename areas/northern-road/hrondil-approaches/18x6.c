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
    addFeature("/lib/environment/features/water/creek.c", "north");
    addItem("/lib/environment/items/objects/signPost.c", "southwest");
    addObject("/areas/northern-road/hrondil-approaches/characters/patrol.c");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/hrondil-approaches/19x6.c");
    addExit("west", "/areas/northern-road/hrondil-approaches/17x6.c");
}
