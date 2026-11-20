//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail intersection");
    setShortDescription("A second trapdoor hides in the ravine floor");
    addFeature("/lib/environment/features/landforms/crag.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/eledhel/vargath-keep/canyon/3x2.c");
    addExit("north", "/areas/eledhel/vargath-keep/canyon/4x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/canyon/4x3.c");
    addExit("east", "/areas/eledhel/vargath-keep/keep-interior/0x2.c");
}
