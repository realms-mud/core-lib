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
    addFeature("/lib/environment/features/vegetation/marked-timber.c",
        "north");
    addItem("/lib/environment/items/objects/outlaw-warning-sign.c",
        "southeast");
    addObject("/areas/northern-road/lower-northern-wilds/characters/ranger.c");
    setEncounterLevel(6);
    addRandomCreature(({ "red fox", "white-tail deer", "outlaw" }));

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/lower-northern-wilds/8x2.c");
    addExit("west", "/areas/northern-road/lower-northern-wilds/6x2.c");
}
