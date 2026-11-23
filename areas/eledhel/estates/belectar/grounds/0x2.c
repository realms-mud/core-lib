//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/plants/common-grain-strips.c",
        "west");
    addBuildingWithDoor(
        "/lib/environment/buildings/trades/granary.c", "south",
        "/areas/eledhel/estates/belectar/granary/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addDecorator("village road corner NE");

    addExit("north", "/areas/eledhel/estates/belectar/grounds/0x1.c");
    addExit("east", "/areas/eledhel/estates/belectar/grounds/1x2.c");
}
