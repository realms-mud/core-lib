//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south");
    setShortDescription("The shelf above the dry cut");
    addFeature("/lib/environment/features/landforms/hill.c", "north");
    addFeature("/lib/environment/features/water/rocky-lake-shore.c", "north");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addExit("south", "/areas/eledhel/west-rural-two/10x0.c");

    addNonCombatCreature(({"white-tail deer"}));
}
