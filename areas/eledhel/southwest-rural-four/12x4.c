//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/meadow.c");
    setShortDescription("The southern road passes a spring-fed hollow");
    addDecorator("village north-south road");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("north", "/areas/eledhel/southwest-rural-four/12x3.c");
    addExit("south", "/areas/eledhel/southwest-rural-four/12x5.c");
}
