//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("A fenced lane through Endur's grazing fields");
    addDecorator("farm path north-east bend");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/eledhel/estates/endur/grounds/0x1.c");
    addExit("south", "/areas/eledhel/estates/endur/grounds/1x2.c");
}
