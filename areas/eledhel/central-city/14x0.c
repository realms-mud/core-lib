//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("A leatherworking shop serves this southern block");
    addObject("/areas/eledhel/central-city/characters/leather-supplier.c");
    addBuildingWithDoor(
        "/lib/environment/buildings/shops/leatherworking-shop.c", "east",
        "/areas/eledhel/central-city/leather-merchant/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addExit("north", "/areas/eledhel/central-city/14x1.c");
    addExit("south", "/areas/eledhel/southern-city/14x9.c");
}
