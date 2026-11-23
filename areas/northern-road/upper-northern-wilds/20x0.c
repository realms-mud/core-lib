//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/crag.c", "north");
    addFeature("/lib/environment/features/trees/pine-stand.c", "south");
    addItem("/lib/environment/items/objects/outlaw-warning-sign.c", "west");
    setEncounterLevel(8);
    addRandomCreature(({ "gray wolf", "outlaw", "boar" }));
    addDecorator("village east-west road");
    addExit("east", "/areas/northern-road/upper-northern-wilds/21x0.c");
    addExit("west", "/areas/northern-road/upper-northern-wilds/19x0.c");
}
