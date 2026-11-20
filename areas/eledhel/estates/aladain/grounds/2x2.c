//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The Aladain village green");
    addDecorator("farm track intersection");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addItem("/lib/environment/items/objects/notice-board.c", "north");
    addExit("north", "/areas/eledhel/estates/aladain/grounds/2x3.c");
    addExit("south", "/areas/eledhel/estates/aladain/grounds/2x1.c");
    addExit("east", "/areas/eledhel/estates/aladain/grounds/3x2.c");
    addExit("west", "/areas/eledhel/estates/aladain/grounds/1x2.c");
}
