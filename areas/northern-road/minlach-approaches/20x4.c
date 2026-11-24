//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "north");
    addFeature("/lib/environment/features/trees/willow-stand.c", "south");
    addItem("/lib/environment/items/objects/well.c", "west");
    addDecorator("village east-west road");
    setEncounterLevel(3);
    addRandomCreature(({ "red fox", "white-tail deer" }));

    addExit("west", "/areas/northern-road/minlach-approaches/19x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/21x4.c");
}
