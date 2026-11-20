//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The road passes a windbreak and a shepherd's lane");
    addDecorator("village road T-west");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/south-coast-one/12x3.c");
    addExit("south", "/areas/eledhel/south-coast-one/12x5.c");
    addExit("west", "/areas/eledhel/south-coast-one/11x4.c");
}
