//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east-west");
    setShortDescription("The creek's narrow stone margin");
    addFeature("/lib/environment/features/water/creek.c", "south");
    addFeature("/lib/environment/features/landforms/hillock.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/evenholt/river-celebuin/13x5.c");
    addExit("east", "/areas/evenholt/river-celebuin/15x5.c");
    addRandomCreature(({ "timber wolf", "white-tail deer" }));
}
