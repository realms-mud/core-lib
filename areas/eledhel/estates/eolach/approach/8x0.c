//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");
    addFeature("/lib/environment/features/trees/ash-stand.c", "east");
    addFeature("/lib/environment/features/trees/yew-stand.c", "west");
    addItem("/lib/environment/items/objects/milestone.c", "southwest");

    addDecorator("village road corner SW");

    addExit("south", "/areas/eledhel/estates/eolach/approach/8x1.c");
    addExit("west", "/areas/eledhel/estates/eolach/approach/7x0.c");
}
