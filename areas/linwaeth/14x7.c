//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The southern pasture track");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/linwaeth/13x7.c");
    addExit("south", "/areas/linwaeth/14x8.c");
}
