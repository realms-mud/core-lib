//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("An orchard sheltered from the coast wind");
    addDecorator("farm path north-east bend");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addItem("/lib/environment/items/objects/notice-board.c", "east");
    addExit("south", "/areas/eledhel/estates/celedrath/grounds/1x2.c");
}
