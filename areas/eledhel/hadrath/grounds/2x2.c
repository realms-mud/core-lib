//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("The garrison yard of Hadrath Watch");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/hadrath/grounds/1x2.c");
    addExit("east", "/areas/eledhel/hadrath/grounds/3x2.c");
    addExit("north", "/areas/eledhel/hadrath/grounds/2x1.c");
    addExit("south", "/areas/eledhel/hadrath/grounds/2x3.c");
}
