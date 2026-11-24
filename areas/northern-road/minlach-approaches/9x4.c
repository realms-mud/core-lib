//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/trees/beech-stand.c", "north");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "south");
    addItem("/lib/environment/items/objects/fox-tracks.c", "southwest");
    addDecorator("village east-west road");
    setEncounterLevel(2);
    addRandomCreature(({ "red fox", "white-tail deer" }));

    addExit("west", "/areas/northern-road/minlach-approaches/8x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/10x4.c");
}
