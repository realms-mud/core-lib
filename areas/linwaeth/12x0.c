//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The King's Road north of Linwaeth");
    addDecorator("village north-south road");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("north", "/areas/eledhel/south-rural-route-17/21x2.c");
    addExit("south", "/areas/linwaeth/12x1.c");
    addFeature("/lib/environment/features/paths/road.c", "south");
}
