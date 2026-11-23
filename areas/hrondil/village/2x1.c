//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addDecorator("village road T-west");

    addExit("north", "/areas/hrondil/village/2x2.c");
    addExit("south", "/areas/hrondil/village/2x0.c");
    addExit("west", "/areas/hrondil/village/1x1.c");
}
