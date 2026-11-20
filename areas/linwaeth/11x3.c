//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The Looming Stag on the market square");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addExit("north", "/areas/linwaeth/11x2.c");
    addExit("east", "/areas/linwaeth/12x3.c");
    addExit("south", "/areas/linwaeth/11x4.c");
    addBuildingWithDoor("/lib/environment/buildings/shops/inn.c",
        "west", "/areas/linwaeth/looming-stag/2x1.c",
        "/lib/environment/doors/plank-door.c");
}
