//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The windfall strip at Tirwen's orchard edge");
    addDecorator("village tree");
    addFeature("/lib/environment/features/trees/apple-stand.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    setEncounterLevel(3);
    addRandomCreature(({ "red fox" }));
    addExit("east", "/areas/eledhel/tirwen/1x1.c");
}
