//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("The paved lane inside the outer gate");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/hadrath/grounds/0x2.c");
    addExit("east", "/areas/eledhel/hadrath/grounds/2x2.c");
    addExit("north", "/areas/eledhel/hadrath/grounds/1x1.c");
}
