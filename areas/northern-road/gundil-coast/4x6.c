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
    addFeature("/lib/environment/features/vegetation/marked-timber.c",
        "north");

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/gundil-coast/5x6.c");
    addExit("west", "/areas/northern-road/gundil-coast/3x6.c");
}
