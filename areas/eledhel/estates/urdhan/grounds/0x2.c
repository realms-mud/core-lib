//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The lane to House Urdhan");
    addDecorator("farm path north-east bend");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/eledhel/southern-rural/2x6.c");
    addExit("east", "/areas/eledhel/estates/urdhan/grounds/1x2.c");
}
