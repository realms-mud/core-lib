//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("A hedge track runs west between small farms");
    addDecorator("village tree");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/eledhel/southwest-rural-five/4x4.c");
    addExit("west", "/areas/eledhel/southwest-rural-five/3x3.c");
}
