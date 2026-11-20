//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-south");
    setShortDescription("The road climbs beneath the northern trees");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addExit("south", "/areas/eledhel/north-road/2x2.c");
    addExit("north", "/areas/eledhel/north-road/2x4.c");

    addRandomCreature(({"timber wolf","gray wolf","outlaw"}));
}
