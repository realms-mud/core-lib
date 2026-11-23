//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/vegetation/ash-coppice.c",
        "northeast");
    addItem("/lib/environment/items/objects/stone-pile.c", "southwest");
    addItem("/lib/environment/items/objects/signPost.c", "northwest");
    setEncounterLevel(4);
    addRandomCreature(({ "gray wolf", "outlaw", "ruffian" }));

    addDecorator("village road T-north");

    addExit("north", "/areas/eledhel/estates/eolach/approach/0x0.c");
    addExit("east", "/areas/northern-road/belathon-eolach/6x4.c");
    addExit("west", "/areas/northern-road/belathon-eolach/4x4.c");
}
