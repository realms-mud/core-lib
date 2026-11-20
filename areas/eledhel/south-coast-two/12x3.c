//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    setShortDescription("A coast trail branches toward a ruined beacon");
    addDecorator("village road T-east");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/eledhel/south-coast-two/12x2.c");
    addExit("south", "/areas/eledhel/south-coast-two/12x4.c");
    addExit("east", "/areas/eledhel/south-coast-two/13x3.c");
}
