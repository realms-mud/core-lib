//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The road-side marker");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("west", "/areas/linwaeth/12x6.c");
    addExit("south", "/areas/linwaeth/13x7.c");
}
