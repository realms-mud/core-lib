//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("A sheep farmer's yard lies beside the wool track");
    addDecorator("village cottage");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/eledhel/southwest-rural-five/8x3.c");
    addExit("south", "/areas/eledhel/southwest-rural-five/9x4.c");
    addObject("/areas/eledhel/southwest-rural-five/characters/shepherd.c");
}
