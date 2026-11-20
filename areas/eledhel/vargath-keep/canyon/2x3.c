//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail T-north");
    setShortDescription("The Hallenach rises from a spring in the cliff");
    addFeature("/lib/environment/features/water/canyon-river.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/vargath-keep/canyon/1x3.c");
    addExit("east", "/areas/eledhel/vargath-keep/canyon/3x3.c");
    addExit("north", "/areas/eledhel/vargath-keep/canyon/2x2.c");
}
