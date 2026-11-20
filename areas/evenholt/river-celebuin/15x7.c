//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-east");
    setShortDescription("The tight ravine below the northwest pass");
    addFeature("/lib/environment/features/landforms/hollow.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/evenholt/river-celebuin/15x6.c");
    addExit("east", "/areas/evenholt/river-celebuin/16x7.c");
    addExit("south", "/areas/evenholt/river-celebuin/15x8.c");
    addRandomCreature(({ "timber wolf", "coyote" }));
}
