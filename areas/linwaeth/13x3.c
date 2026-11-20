//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("Johan's blacksmith shop");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addExit("west", "/areas/linwaeth/12x3.c");
    addExit("north", "/areas/linwaeth/13x2.c");
    addExit("south", "/areas/linwaeth/13x4.c");
    addBuildingWithDoor("/lib/environment/buildings/trades/craft-workshop.c",
        "east", "/areas/linwaeth/smithy/0x1.c",
        "/lib/environment/doors/plank-door.c");
}
