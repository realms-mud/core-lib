//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The eastern market lane");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addExit("west", "/areas/linwaeth/12x2.c");
    addExit("south", "/areas/linwaeth/13x3.c");
}
