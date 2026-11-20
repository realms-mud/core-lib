//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The stable yard");
    addDecorator("farm track T-north");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addBuildingWithDoor("/lib/environment/buildings/trades/stable.c",
        "west", "/areas/eledhel/estates/aladain/stable/0x0.c",
        "/lib/environment/doors/plank-door.c");
    addExit("north", "/areas/eledhel/estates/aladain/grounds/1x2.c");
    addExit("east", "/areas/eledhel/estates/aladain/grounds/2x1.c");
}
