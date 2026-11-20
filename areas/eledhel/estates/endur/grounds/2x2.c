//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The Endur manor yard");
    addDecorator("farm track intersection");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/estates/endur/grounds/1x2.c");
    addExit("north", "/areas/eledhel/estates/endur/grounds/2x1.c");
    addExit("east", "/areas/eledhel/estates/endur/grounds/3x2.c");
}
