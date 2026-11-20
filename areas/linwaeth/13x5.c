//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The town's cart yard");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addExit("north", "/areas/linwaeth/13x4.c");
    addExit("west", "/areas/linwaeth/12x5.c");
}
