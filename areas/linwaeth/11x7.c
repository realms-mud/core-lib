//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The west track toward the outcast camp");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/linwaeth/11x6.c");
    addExit("east", "/areas/linwaeth/12x7.c");
    addExit("south", "/areas/linwaeth/10x8.c");
    addItem("/lib/environment/items/objects/notice-board.c", "west");
}
