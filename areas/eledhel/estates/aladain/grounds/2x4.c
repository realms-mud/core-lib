//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The approach to the keep");
    addDecorator("farm track T-south");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/eledhel/estates/aladain/grounds/2x3.c");
    addExit("west", "/areas/eledhel/estates/aladain/grounds/1x4.c");
    addExit("east", "/areas/eledhel/estates/aladain/grounds/3x4.c");
}
