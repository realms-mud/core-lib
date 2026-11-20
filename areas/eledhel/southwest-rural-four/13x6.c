//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/meadow.c");
    setShortDescription("A narrow pasture track follows the stream east");
    addDecorator("village east-west road");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/southwest-rural-four/12x6.c");
    addExit("east", "/areas/eledhel/southwest-rural-four/14x6.c");
}
