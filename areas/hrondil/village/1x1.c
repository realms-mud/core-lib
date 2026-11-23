//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addObject("/areas/hrondil/characters/village-reeve.c");

    addDecorator("village road intersection");

    addExit("north", "/areas/hrondil/village/1x2.c");
    addExit("east", "/areas/hrondil/village/2x1.c");
    addExit("south", "/areas/hrondil/village/1x0.c");
    addExit("west", "/areas/hrondil/village/0x1.c");
}
