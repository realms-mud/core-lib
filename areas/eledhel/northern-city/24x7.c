//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/pier.c");
    setShortDescription("A fish landing and provision stall on the northern pier");
    addFeature("/lib/environment/features/water/ocean.c", "east");
    addItem("/lib/environment/items/marine/crate-of-fish.c", "west");
    addItem("/lib/environment/items/marine/fish-cleaning-table.c", "north");
    addShop("/lib/environment/shopInventories/provisions.c");
    addDecorator("dock");
    addObject("/areas/eledhel/northern-city/characters/dock-provisioner.c");
    addObject("/areas/eledhel/northern-city/characters/north-dock-customer.c");
    addExit("north", "/areas/eledhel/northern-city/24x8.c");
    addExit("west", "/areas/eledhel/northern-city/23x7.c");
}
