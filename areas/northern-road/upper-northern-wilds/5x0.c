//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/landforms/crag.c", "north");
    addFeature("/lib/environment/features/water/spring.c", "south");
    addItem("/lib/environment/items/objects/outlaw-warning-sign.c", "east");
    addItem("/lib/environment/items/objects/rope-bundle.c", "west");
    addDecorator("village east-west road");
    addExit("east", "/areas/northern-road/upper-northern-wilds/6x0.c");
    addExit("west", "/areas/northern-road/upper-northern-wilds/4x0.c");
    addExit("north",
        "/areas/northern-road/upper-northern-wilds/hollow-mill/yard.c");
}
