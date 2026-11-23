//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The mill yard beside Dhorlen's old road");
    addDecorator("village road T-north");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("west", "/areas/eledhel/dhorlen/1x2.c");
    addExit("east", "/areas/eledhel/dhorlen/3x2.c");
    addBuildingWithDoor("/lib/environment/buildings/trades/water-mill.c",
        "north", "/areas/eledhel/dhorlen/mill/0x1.c",
        "/lib/environment/doors/plank-door.c");
}
