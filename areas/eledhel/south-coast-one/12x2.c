//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("A drove-country lane leaves the King's Road");
    addDecorator("village road T-east");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/eledhel/south-coast-one/12x1.c");
    addExit("south", "/areas/eledhel/south-coast-one/12x3.c");
    addExit("east", "/areas/eledhel/south-coast-one/13x2.c");
}
