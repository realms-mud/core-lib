//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior north-west corner hallway");
    addFeature("/lib/environment/features/caves/timber-supports.c",
        "south");
    addItem("/lib/environment/items/marine/barrel-of-water.c", "east");
    setEncounterLevel(2);
    addRandomCreature(({ "bat" }));

    addExit("north", "/areas/eledhel/central-rural/cellar/3x1.c");
    addExit("west", "/areas/eledhel/central-rural/cellar/2x2.c");
}
