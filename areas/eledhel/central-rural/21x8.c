//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    setShortDescription("The overgrown cart track");
    addDecorator("farm track T-east");
    addItem("/lib/environment/items/objects/broken-cart.c", "east");
    addFeature("/lib/environment/features/trees/birch-stand.c", "west");
    setEncounterLevel(3);
    addRandomCreature(({ "red fox", "white-tail deer" }));
    addExit("south", "/areas/eledhel/central-rural/21x7.c");
    addExit("east", "/areas/eledhel/central-rural/22x8.c");
    addExit("north", "/areas/eledhel/central-rural/21x9.c");
}
