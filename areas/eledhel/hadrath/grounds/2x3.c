//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("The well and stores below the garrison yard");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("north", "/areas/eledhel/hadrath/grounds/2x2.c");
}
