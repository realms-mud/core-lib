//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    setShortDescription("A game trail enters the copse from the farms");
    addDecorator("village tree");
    addFeature("/lib/environment/features/landforms/crag.c", "none");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("north", "/areas/eledhel/southwest-rural-five/3x3.c");
    addRandomCreature(({ "gray wolf", "red fox", "outlaw" }));
}
