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
    addItem("/lib/environment/items/objects/wooden-fence.c", "northwest");
    setEncounterLevel(1);
    addRandomCreature(({ "groundhog", "white-tail deer", "red fox" }));

    addDecorator("village east-west road");

    addExit("east", "/areas/northern-road/north-gate/6x2.c");
    addExit("west", "/areas/northern-road/north-gate/4x2.c");
}
