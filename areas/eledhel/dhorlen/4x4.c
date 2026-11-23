//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("Water eddies below the southern bridge abutment");
    addDecorator("village tree");
    addFeature("/lib/environment/features/water/river.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    setEncounterLevel(3);
    addRandomCreature(({ "otter", "red fox" }));
    addExit("west", "/areas/eledhel/dhorlen/3x4.c");
}
