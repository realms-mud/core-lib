//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail west");
    setShortDescription("A covered shaft drops into the limestone cave");
    addFeature("/lib/environment/features/landforms/crag.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("west", "/areas/eledhel/vargath-keep/approach/3x2.c");
    addExit("down", "/areas/eledhel/vargath-keep/limestone-caves/0x0.c");
}
