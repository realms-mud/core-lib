//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("The King's Road follows the ridge beneath the east");
    addDecorator("village east-west road");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("west", "/areas/eledhel/southwest-rural-four/12x9.c");
    addExit("east", "/areas/eledhel/southwest-rural-four/14x9.c");
}
