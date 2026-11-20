//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("Linwaeth's northern gate");
    addDecorator("village north-south road");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addExit("north", "/areas/linwaeth/12x0.c");
    addExit("south", "/areas/linwaeth/12x2.c");
    addObject("/areas/linwaeth/characters/guard.c");
}
