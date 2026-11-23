//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/vegetation/marked-timber.c",
        "north");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "south");
    addItem("/lib/environment/items/objects/broken-cart.c", "southwest");
    setEncounterLevel(4);
    addRandomCreature(({ "gray wolf", "outlaw", "ruffian" }));

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/northern-manor/21x6.c");
    addExit("west", "/areas/northern-road/northern-manor/19x6.c");
}
