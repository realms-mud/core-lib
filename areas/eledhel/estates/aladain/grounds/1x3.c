//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The village well and common");
    addDecorator("farm track T-east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addItem("/lib/environment/items/objects/notice-board.c", "west");
    addExit("north", "/areas/eledhel/estates/aladain/grounds/1x4.c");
    addExit("south", "/areas/eledhel/estates/aladain/grounds/1x2.c");
    addExit("east", "/areas/eledhel/estates/aladain/grounds/2x3.c");
}
