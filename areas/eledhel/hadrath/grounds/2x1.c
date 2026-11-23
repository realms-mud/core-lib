//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("The keep's defended forecourt");
    addDecorator("village keep gate");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/eledhel/hadrath/grounds/2x2.c");
    addExit("north", "/areas/eledhel/hadrath/keep-interior/2x0.c");
}
