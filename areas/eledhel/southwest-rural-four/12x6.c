//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/meadow.c");
    setShortDescription("A stream crossing serves the eastern pastures");
    addDecorator("village road T-east");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/eledhel/southwest-rural-four/12x5.c");
    addExit("south", "/areas/eledhel/southwest-rural-four/12x7.c");
    addExit("east", "/areas/eledhel/southwest-rural-four/13x6.c");
}
