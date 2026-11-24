//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "north");
    addFeature("/lib/environment/features/water/field-drain.c", "south");
    addItem("/lib/environment/items/objects/stone-pile.c", "west");
    addDecorator("village east-west road");
    setEncounterLevel(2);
    addRandomCreature(({ "red fox", "white-tail deer" }));

    addExit("west", "/areas/northern-road/minlach-approaches/2x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/4x4.c");
}
