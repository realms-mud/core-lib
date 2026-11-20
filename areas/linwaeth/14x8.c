//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The caravan ambush ground");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "south");
    addExit("north", "/areas/linwaeth/14x7.c");
    addItem("/lib/environment/items/objects/packing-crate.c", "west");
}
