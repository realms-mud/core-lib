//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The public well");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addExit("north", "/areas/linwaeth/13x3.c");
    addExit("west", "/areas/linwaeth/12x4.c");
    addExit("south", "/areas/linwaeth/13x5.c");
}
