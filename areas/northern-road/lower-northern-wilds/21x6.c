//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-mountain.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "north");
    addItem("/lib/environment/items/objects/outlaw-warning-sign.c",
        "southeast");
    setEncounterLevel(6);
    addRandomCreature(({ "gray wolf", "boar", "ruffian" }));

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/lower-northern-wilds/22x6.c");
    addExit("west", "/areas/northern-road/lower-northern-wilds/20x6.c");
}
