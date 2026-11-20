//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    setShortDescription("A rocky lookout over the eastern stream");
    addDecorator("village tree");
    addFeature("/lib/environment/features/landforms/crag.c", "none");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("south", "/areas/eledhel/southwest-rural-four/14x6.c");
    addRandomCreature(({ "gray wolf", "red fox" }));
}
