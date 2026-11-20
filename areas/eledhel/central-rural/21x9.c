//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    setShortDescription("The concealed woodland camp");
    addDecorator("farm path south dead end");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");
    addItem("/lib/environment/items/objects/sack-pile.c", "east");
    addItem("/lib/environment/items/marine/coiled-rope.c", "north");
    setEncounterLevel(5);
    addRandomCreature(({ "outlaw" }));
    addExit("south", "/areas/eledhel/central-rural/21x8.c");
}
