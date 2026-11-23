//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addObject("/areas/eledhel/estates/erator/characters/steward.c");

    addDecorator("village road intersection");

    addExit("north", "/areas/eledhel/estates/erator/grounds/2x0.c");
    addExit("east",
        "/areas/eledhel/estates/erator/keep-interior/0x0.c");
    addExit("south", "/areas/eledhel/estates/erator/grounds/2x2.c");
    addExit("west", "/areas/eledhel/estates/erator/grounds/1x1.c");
}
