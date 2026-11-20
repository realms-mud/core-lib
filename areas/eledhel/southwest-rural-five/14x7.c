//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    setShortDescription("A rise overlooks the road and Linwaeth's walls");
    addDecorator("village tree");
    addFeature("/lib/environment/features/landforms/crag.c", "none");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("south", "/areas/eledhel/southwest-rural-five/14x8.c");
    addRandomCreature(({ "gray wolf", "white-tail deer" }));
}
