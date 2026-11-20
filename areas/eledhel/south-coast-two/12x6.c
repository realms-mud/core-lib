//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    setShortDescription("A rough path descends to a wreck-strewn shore");
    addDecorator("village road T-east");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/eledhel/south-coast-two/12x5.c");
    addExit("south", "/areas/eledhel/south-coast-two/12x7.c");
    addExit("east", "/areas/eledhel/south-coast-two/13x6.c");
}
