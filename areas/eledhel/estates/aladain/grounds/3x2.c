//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The estate mill yard");
    addDecorator("farm track T-north");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "south");
    addBuildingWithDoor(
        "/lib/environment/buildings/trades/water-mill.c", "east",
        "/areas/eledhel/estates/aladain/mill/0x0.c",
        "/lib/environment/doors/plank-door.c");
    addExit("north", "/areas/eledhel/estates/aladain/grounds/3x3.c");
    addExit("west", "/areas/eledhel/estates/aladain/grounds/2x2.c");
}
