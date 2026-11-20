//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail intersection");
    setShortDescription("The ravine narrows beneath concealed ambush ledges");
    addFeature("/lib/environment/features/landforms/precipice.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/vargath-keep/canyon/2x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/canyon/4x2.c");
    addExit("north", "/areas/eledhel/vargath-keep/canyon/3x1.c");
    addExit("south", "/areas/eledhel/vargath-keep/canyon/3x3.c");
    addRandomCreature(({ "outlaw", "ruffian", "knight of the storm" }));
}
