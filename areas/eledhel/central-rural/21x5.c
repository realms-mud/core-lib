//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The pasture lane");
    addDecorator("farm track T-west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addItem("/lib/environment/items/objects/boundary-stone.c", "east");
    addBuildingWithDoor("/lib/environment/buildings/trades/barn.c",
        "west", "/areas/eledhel/central-rural/20x5.c",
        "/lib/environment/doors/plank-door.c");
    addExit("north", "/areas/eledhel/central-rural/21x6.c");
    addExit("south", "/areas/eledhel/central-rural/21x4.c");
}
