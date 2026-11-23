//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/landforms/mountain.c", "east");
    addItem("/lib/environment/items/objects/milestone.c", "southwest");

    addDecorator("village road corner NW");

    addExit("west", "/areas/northern-road/lower-northern-wilds/23x8.c");
    addExit("north", "/areas/northern-road/upper-northern-wilds/0x0.c");
}
