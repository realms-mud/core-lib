//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail intersection");
    setShortDescription("Blocky runes circle the symbol on the northern face");
    addFeature("/lib/environment/features/landforms/crag.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/vargath-keep/canyon/1x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/canyon/3x2.c");
    addExit("north", "/areas/eledhel/vargath-keep/canyon/2x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/canyon/2x3.c");
}
