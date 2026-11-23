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
    addFeature("/lib/environment/features/trees/birch-stand.c", "north");
    addItem("/lib/environment/items/objects/outlaw-warning-sign.c",
        "southeast");
    setEncounterLevel(5);
    addRandomCreature(({ "gray wolf", "outlaw", "ruffian" }));

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/hrondil-approaches/22x6.c");
    addExit("west", "/areas/northern-road/hrondil-approaches/20x6.c");
}
