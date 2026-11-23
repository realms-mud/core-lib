//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");
    addItem("/lib/environment/items/objects/boundary-stone.c", "west");

    setEncounterLevel(7);
    addRandomCreature(({ "gray wolf", "boar", "outlaw" }));

    addDecorator("village road intersection");

    addExit("south", "/areas/northern-road/lower-northern-wilds/24x8.c");
    addExit("west", "/areas/northern-road/upper-northern-wilds/windward-inn/common-room.c");
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/phaedra-outpost/courtyard.c");
    addExit("east", "/areas/northern-road/upper-northern-wilds/1x0.c");
}
