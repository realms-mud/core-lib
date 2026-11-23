//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("Pasture fences follow the lane toward the sheepfold");
    addDecorator("village east-west road");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addFeature("/lib/environment/features/paths/road.c", "east");
    setEncounterLevel(3);
    addRandomCreature(({ "red fox", "boar" }));
    addExit("west", "/areas/eledhel/tirwen/4x1.c");
    addExit("east", "/areas/eledhel/tirwen/6x1.c");
}
