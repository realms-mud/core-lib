//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The grazing lane south of Linwaeth");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/linwaeth/13x6.c");
    addExit("west", "/areas/linwaeth/12x7.c");
    addExit("east", "/areas/linwaeth/14x7.c");
}
