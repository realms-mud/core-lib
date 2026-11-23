//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/plants/common-root-beds.c",
        "north");
    addItem("/lib/environment/items/objects/wooden-fence.c", "west");
    setEncounterLevel(1);
    addRandomCreature(({ "groundhog", "white-tail deer", "red fox" }));

    addDecorator("village road corner SE");

    addExit("east", "/areas/northern-road/north-gate/market-gardens/1x0.c");
    addExit("south", "/areas/northern-road/north-gate/market-gardens/0x1.c");
}
