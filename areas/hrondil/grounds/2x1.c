//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addDecorator("village road intersection");

    addExit("north", "/areas/hrondil/grounds/2x0.c");
    addExit("east", "/areas/hrondil/keep-interior/0x0.c");
    addExit("south", "/areas/hrondil/grounds/2x2.c");
    addExit("west", "/areas/hrondil/grounds/1x1.c");
}
