//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The kitchen-garden lane");
    addDecorator("farm path north-east bend");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/eledhel/estates/oeldhen/grounds/0x2.c");
    addExit("east", "/areas/eledhel/estates/oeldhen/grounds/2x2.c");
    addExit("north", "/areas/eledhel/estates/oeldhen/grounds/1x1.c");
}
