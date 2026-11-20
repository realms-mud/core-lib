//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    setShortDescription("The road climbs away from the headland shore");
    addDecorator("village north-south road");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("north", "/areas/eledhel/south-coast-two/12x6.c");
    addExit("south", "/areas/eledhel/south-coast-two/12x8.c");
}
