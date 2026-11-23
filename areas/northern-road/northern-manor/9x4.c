//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/barley-field.c", "north");
    addFeature("/lib/environment/features/water/field-drain.c", "south");
    addItem("/lib/environment/items/objects/broken-cart.c", "northeast");
    setEncounterLevel(4);
    addRandomCreature(({ "gray wolf", "outlaw", "ruffian" }));

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/northern-manor/10x4.c");
    addExit("west", "/areas/northern-road/northern-manor/8x4.c");
}
