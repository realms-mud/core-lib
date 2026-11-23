//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/ash-stand.c", "south");
    addFeature("/lib/environment/features/landforms/hollow.c", "north");
    addItem("/lib/environment/items/objects/broken-cart.c", "southwest");
    setEncounterLevel(4);
    addRandomCreature(({ "gray wolf", "outlaw", "ruffian" }));

    addDecorator("village east-west road");

    addExit("east", "/areas/eledhel/estates/eolach/approach/6x1.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/4x1.c");
}
