//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    setShortDescription("The southern road skirts a rocky bluff");
    addDecorator("village north-south road");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/water/rocky-ocean-shore.c");
    addExit("north", "/areas/eledhel/south-coast-two/12x1.c");
    addExit("south", "/areas/eledhel/south-coast-two/12x3.c");
}
