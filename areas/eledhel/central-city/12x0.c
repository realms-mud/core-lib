//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuildingWithDoor("/lib/environment/buildings/shops/furrier.c",
        "east", "/areas/eledhel/central-city/furrier/0x0.c",
        "/lib/environment/doors/plank-door.c");
    addBuildingWithDoor("/lib/environment/buildings/shops/tavern.c",
        "west", "/areas/eledhel/central-city/tavern/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    setShortDescription("Furrier and tavern fronts share this lively street");
    addObject("/areas/eledhel/central-city/characters/furrier-street-shopper.c");

    addExit("north", "/areas/eledhel/central-city/12x1.c");
    addExit("south", "/areas/eledhel/southern-city/12x9.c");
}
