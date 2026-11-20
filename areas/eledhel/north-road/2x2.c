//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-west");
    setShortDescription("The northern road's western fork");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addExit("west", "/areas/eledhel/north-road/1x2.c");
    addExit("south", "/areas/eledhel/north-road/2x1.c");
    addExit("north", "/areas/eledhel/north-road/2x3.c");

    addRandomCreature(({ "white-tail deer", "red fox", "outlaw" }));
}
