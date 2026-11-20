//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    setShortDescription("A lane leaves the gate road along the city fields");
    addDecorator("village north-south road");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("south", "/areas/eledhel/southwest-rural-five/14x9.c");
    addExit("north", "/areas/eledhel/southwest-rural-five/14x7.c");
}
