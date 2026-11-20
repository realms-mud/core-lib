//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/meadow.c");
    setShortDescription("The grass-grown edge of the pasture");
    addDecorator("farm path west dead end");
    addFeature("/lib/environment/features/paths/path.c", "west");
    setEncounterLevel(2);
    addRandomCreature(({ "red fox", "white-tail deer" }));
    addExit("west", "/areas/eledhel/estates/aladain/grounds/2x1.c");
}
