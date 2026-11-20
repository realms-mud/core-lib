//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("A track skirts an abandoned charcoal shed");
    addDecorator("village road T-south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/eledhel/south-coast-one/11x4.c");
    addExit("south", "/areas/eledhel/south-coast-one/10x5.c");
    addRandomCreature(({ "ruffian", "timber wolf", "red fox" }));
}
