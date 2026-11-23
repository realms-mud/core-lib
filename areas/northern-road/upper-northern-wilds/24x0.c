//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/promontory.c", "north");
    addFeature("/lib/environment/features/water/spring.c", "south");
    addItem("/lib/environment/items/objects/boundary-stone.c", "east");
    addDecorator("village east-west road");
    addExit("west", "/areas/northern-road/upper-northern-wilds/23x0.c");
}
