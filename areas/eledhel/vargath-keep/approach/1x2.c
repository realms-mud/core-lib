//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east-west");
    setShortDescription("A track crosses the exposed western foothills");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("west", "/areas/eledhel/vargath-keep/approach/0x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/approach/2x2.c");
    addRandomCreature(({ "outlaw", "wolverine", "red wolf" }));
}
