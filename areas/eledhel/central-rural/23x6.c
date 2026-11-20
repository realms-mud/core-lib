//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("Pera's produce stand");
    addDecorator("farm track intersection");
    addItem("/lib/environment/items/furniture/counter.c", "east");
    addItem("/lib/environment/items/objects/sack-pile.c", "east");
    addFeature("/lib/environment/features/plants/common-kitchen-garden.c",
        "northeast");
    addShop("/lib/environment/shopInventories/provisions.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addObject("/areas/eledhel/central-rural/characters/pera/pera.c");

    addExit("south", "/areas/eledhel/central-rural/23x5.c");
    addExit("west", "/areas/eledhel/central-rural/22x6.c");
    addExit("north", "/areas/eledhel/central-rural/23x7.c");
    addExit("east", "/areas/eledhel/central-rural/24x6.c");
}
