//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("The outer gate of Hadrath Watch");
    addDecorator("village keep gate");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/hadrath/watchlands/19x5.c");
    addExit("east", "/areas/eledhel/hadrath/grounds/1x2.c");
}
