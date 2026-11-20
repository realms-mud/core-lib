//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("A track leads to a wool-sorting shed");
    addDecorator("village cottage");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/southwest-rural-five/12x4.c");
    addExit("north", "/areas/eledhel/southwest-rural-five/13x3.c");
}
