//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The stream mill's loading yard");
    addDecorator("farm track T-west");
    addFeature("/lib/environment/features/water/river-with-bridge.c", "west");
    addItem("/lib/environment/items/crafts/flour-sack.c", "east");
    addBuildingWithDoor("/lib/environment/buildings/trades/water-mill.c",
        "south", "/areas/eledhel/central-rural/23x2.c",
        "/lib/environment/doors/plank-door.c");
    addExit("north", "/areas/eledhel/central-rural/23x4.c");
    addExit("west", "/areas/eledhel/central-rural/22x3.c");
}
